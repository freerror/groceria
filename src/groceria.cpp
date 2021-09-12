#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "fb_groceria.h"
#include "fb_groceria.cpp"
#include <wx/wx.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class Item
{
public:
    Item(int id, std::string name)
        : id(id), name(name)
    {
        this->required_count = 0;
        this->del = false;
    }

    void increment(char action = '+')
    {
        switch (action) {
            case '+':
                this->required_count++;
                break;
            case '-':
                this->required_count--;
                break;
            case '0':
                this->required_count = 0;
                break;
        }
    }

    void adjust_required_count(int amount)
    {
        // must not ever become negative
        this->required_count += amount;
        if (this->required_count < 0)
        {
            this->required_count = 0;
        }
    }

    void set_del(const bool state)
    {
        this->del = state;
    }

    bool deleted()
    {
        return this->del;
    }

    int get_required()
    {
        return this->required_count;
    }

    int get_id()
    {
        return this->id;
    }

    std::string get_name()
    {
        return this->name;
    }

private:
    const int id;
    std::string name;
    int required_count;
    bool del = false;
};


class Ingredient : public Item
{
public:
    Ingredient(int id, std::string name, std::string aisle) : Item(id, name)
    {
        this->aisle = aisle;
    }

    void set_aisle(const std::string aisle_name)
    {
        this->aisle = aisle_name;
    }

    std::string get_aisle()
    {
        return this->aisle;
    }

private:
    std::string aisle;
};


class Recipe : public Item
{
public:
    using Item::Item;
    Recipe(int id, std::string name, std::vector<int> ingredients) : Item(id, name)
    {
        this->ingredients = ingredients;
    }

    int get_outstanding()
    {
        return this->outstanding;
    }

    void set_outstanding(int amount)
    {
        this->outstanding = amount;
    }

    void add_ingred(const int& ingred)
    {
        this->ingredients.push_back(ingred);
    }

    void clear_ingreds()
    {
        this->ingredients.clear();
    }

    std::vector<int> get_ingreds()
    {
        return ingredients;
    }

    std::string str_ingreds()
    {
        std::string str;
        for (const auto &val : ingredients)
        {
            str += std::to_string(val) + ", ";
        }
        return str;
    }

private:
    std::vector<int> ingredients;
    int outstanding = 0;
};

// std::string *getRequiredIngredients(std::string *items,
//                                     std::string *recipes,
//                                     std::string *ingredients,
//                                     std::string *required_ingredients){
//     // TODO Cull not needed recipe ingredients
//     // TODO Get new recipe ingredients
//     // TODO Cull ingredient items
//     // TODO Add ingredient items
//     // TODO return required ingredients
//     return 0;
// };

template<typename T>
int find_item_id(std::vector<T> &vect, std::string name)
{
    for (auto &val : vect)
    {
        if (name == val.get_name())
        {
            return val.get_id();
        }
    }
    return -1;
};


// returns true if provided val found in provided array
// template<typename T, typename O, std::size_t N>
// bool in_this_array(T (&arr)[N], O &val)
// {
//     return std::find(std::begin(arr),
//                      std::end(arr),
//                      val
//                     ) != std::end(arr);
// };


// Take vector and an index, then return matching integer id or -1 if found
template<typename T>
int find_vect_index(std::vector<T> &vect, int id)
{
    int found_ind = 0;
    for (auto &val : vect)
    {
        if (val.get_id() == id)
        {
            return found_ind;
        }
        found_ind ++;
    }
    return -1;
};

// given vector of Ingredients and an id, return name.
std::string get_ingredient_from_id(std::vector<Ingredient>& ingredients, int id)
{
    for (auto& ingredient : ingredients)
    {
        if (ingredient.get_id() == id)
        {
            return ingredient.get_name();
        }
    }
    return "MISSING";
}

// given vector of ingredients and a name, returns aisle
std::string get_aisle_from_name(std::vector<Ingredient>& ingredients,
                               const std::string& name)
{
    for (auto &ingredient : ingredients)
    {
        if (name == ingredient.get_name())
        {
            return ingredient.get_aisle();
        }

    }
    return "";
}

void parse_prefs(std::vector<Ingredient>& ingredients,
                 std::vector<Recipe>& recipes,
                 const std::string& recipe_file,
                 const std::string& ingred_file)
{
    // uses ingredients.cfg and recipes.cfg to populate the respective
    // vectors of Ingredient and Recipe objects
    std::ifstream recfile{recipe_file};
    std::ifstream ingfile{ingred_file};
    std::string line;
    std::string cur_recipe;
    std::vector<std::string> seen_ingreds;
    std::unordered_map<std::string, std::string> conf_ingreds;  // ingreds broken down by aisle
    int char_pos;
    int recipe_id = 0;
    int ingred_id = 0;
    int prev_ingred_id;
    bool unfound;
    
    // Populate ingredients with ingredients
    while (std::getline(ingfile, line, '\n'))
    {
        ingredients.push_back({
            ingred_id,
            line.substr(line.find(": ") + 2),
            line.substr(0, line.find(": "))
        });
        ingred_id++;
    }

    // make recipe conf
    while (std::getline(recfile, line, '\n'))
    {
        // set unfound to help identify ingredients in recipes but not ingredients
        unfound = true;  // starts true. if remains true then unfound exists

        // if the line starts with # it's a new recipe name
        if (line.find("#") != std::string::npos)
        {
            cur_recipe = line.substr(2);
            std::cout << "Recipe found: " << cur_recipe << "\n";
            recipes.push_back({recipe_id, cur_recipe});
            recipe_id++;
        }
        // assumed to be ingredient if more than just a blank line
        else if (line.length() > 1)
        {
            for (auto &ingred : ingredients)
            {
                if (ingred.get_name() == line)
                {
                    ingred_id = ingred.get_id();
                    recipes.back().add_ingred(ingred_id);
                    std::cout << "added: " << " " << ingred_id << " " << line << "\n";
                    unfound = false;  // must have found it for this line
                    break;
                }
            }
            if (unfound)  // should only exuecute if didn't match an ingred in preceding code
            {
                // ensure we add any ingredients only found in recipes
                ingred_id = ingredients.size();
                ingredients.push_back({
                    ingred_id,
                    line,
                    "Unspecified"
                });  // to ingredients
                recipes.back().add_ingred(ingred_id);  // to recipes
            }
        }
        else
        {
            std::cout << "[blank line]"
                      << "\n";
        }
    }
    recfile.close();
    ingfile.close();
};

bool write_prefs(std::vector<Ingredient>& ingredients,
                 std::vector<Recipe>& recipes,
                 const std::string& recipe_file,
                 const std::string& ingred_file)
{
    std::ofstream recfile{recipe_file};
    std::ofstream ingfile{ingred_file};
    std::vector<std::string> sorted_lines;

    for (auto &ingredient : ingredients) {
        if (!ingredient.deleted())
        {
            sorted_lines.push_back(ingredient.get_aisle() + ": " + ingredient.get_name() + "\n");
            // ingfile << ingredient.get_aisle() << ": "
            //         << ingredient.get_name() << "\n";
        }
    }
    std::sort(sorted_lines.begin(), sorted_lines.end());
    for (auto &l : sorted_lines)
    {
        ingfile << l;
    }
    for (auto &recipe : recipes) {
        if (!recipe.deleted())
        {
            recfile << "# " << recipe.get_name() << "\n";
            for (auto &ing_id : recipe.get_ingreds())
            {
                recfile << get_ingredient_from_id(ingredients, ing_id) << "\n";
            }
            recfile << "\n";
        }
    }
    ingfile.close();
    recfile.close();
    return true;
}


void demo_recipe_ingreds(std::vector<Recipe>& recipes, const std::string title)
{
    std::cout << "\n\n" << title << "\n"
              << "============================\n\n"
              << std::left
              << std::setw(40) << "recipe name"
              << std::setw(50) << "ingredient ids"
              << "\n"
              << std::setw(40) << "-----------"
              << std::setw(50) << "--------------"
              << "\n";
    for (auto &val : recipes)
    {
        std::cout << std::left
                  << std::setw(40) << val.get_name()
                  << std::setw(50) << val.str_ingreds()
                  << "\n";
    }
}


template<typename T>
void demo_pref_vect(std::vector<T>& vect, const std::string title)
{
    std::cout << "\n\n" << title << "\n"
              << "============================\n\n"
              << std::left
              << std::setw(5) << "id" 
              << std::setw(30) << "name" 
              << std::setw(5) << "required_count" 
              << "\n"
              << std::setw(5) << "--"
              << std::setw(30) << "----" 
              << std::setw(5) << "-----" 
              << "\n";
    for (auto &val : vect)
    {
        std::cout << std::left
                  << std::setw(5) << val.get_id()
                  << std::setw(30) << val.get_name()
                  << std::setw(5) << val.get_required()
                  << "\n";
    }
    std::cout << "\n\n\n";
};


void update_ingredients(std::vector<Recipe>& recipes,
                        std::vector<Ingredient>& ingredients)
{
    std::vector<int> new_ingreds;
    std::vector<int> recipe_ingreds;
    int outstanding_amount;
    std::string activity_description;
    int ing_vect_index;
    for (auto &val : recipes)
    {
        outstanding_amount = val.get_outstanding();
        if (outstanding_amount > 0)
        {
            std::cout << "\nAdd recipe choice: " << val.get_name();
            recipe_ingreds = val.get_ingreds();
            new_ingreds.insert(new_ingreds.end(),
                            recipe_ingreds.begin(),
                            recipe_ingreds.end());
            activity_description = "add";
            break;  // will need to be refactored if multi-select is implemented
        }
        else if (outstanding_amount < 0)
        {
            std::cout << "\nRemove recipe choice: " << val.get_name();
            recipe_ingreds = val.get_ingreds();
            new_ingreds.insert(new_ingreds.end(),
                            recipe_ingreds.begin(),
                            recipe_ingreds.end());
            activity_description = "remove";
            break;
        }
    }
    if (outstanding_amount != 0)
    {
        std::sort(new_ingreds.begin(), new_ingreds.end());
        std::cout << "\n\nUpdate ingredients:";
        for (auto &val : new_ingreds)
        {
            // find and update the appropriate ingredients
            ing_vect_index = find_vect_index(ingredients, val);
            ingredients[ing_vect_index].adjust_required_count(outstanding_amount);
            std::cout << "\n "
                      << activity_description << " "
                      << ing_vect_index
                      << " found from id "
                      << val;
        }
        std::cout << "\n";
    }
};


// void test_scenario(std::vector<Recipe>& recipes,
//                    std::vector<Ingredient>& ingredients)
// {
//     int choices[4] = {3, 5, 21, 10};
//     int cur_ingred;

//     for (auto &val : recipes)
//     {
//         cur_ingred = val.get_id();
//         if (in_this_array(choices, cur_ingred))
//         {
//             val.increment('+');
//         }
//     }
// };


std::vector<std::string> vect_unique_aisles(std::vector<Ingredient>& ingreds)
{
    std::vector<std::string> unique_aisles;
    std::vector<std::string>::iterator it;
    for (auto &ing : ingreds)
    {
        unique_aisles.push_back(ing.get_aisle());
    }
    std::sort(unique_aisles.begin(), unique_aisles.end());
    it = std::unique(unique_aisles.begin(), unique_aisles.end());
    unique_aisles.resize(std::distance(unique_aisles.begin(), it));

    return unique_aisles;
}


std::string get_grocery_list(std::vector<Ingredient>& ingredients)
{
    std::string grocery_list = "## Grocery List\n";
    std::vector<std::string> unique_aisles = vect_unique_aisles(ingredients);

    for (auto &aisle : unique_aisles)
    {
        grocery_list += "### " + aisle + "\n";
        for (auto &ing : ingredients)
        {
            if (aisle == ing.get_aisle() && ing.get_required() == 1)
            {
                grocery_list += "- [ ] " + ing.get_name() + "\n";
            }
            else if (aisle == ing.get_aisle() && ing.get_required() > 1)
            {
                grocery_list += "- [ ] " + ing.get_name() +
                                " (" + std::to_string(ing.get_required()) + ")" + "\n";
            }
        }
    }

    return grocery_list;
};

std::string get_meal_list(std::vector<Recipe> recipes)
{
    std::string meal_list = "\n## Meals this week\n";
    for (auto &recipe : recipes)
    {
        if (recipe.get_required() == 1)
        {
            meal_list += "- " + recipe.get_name() + "\n";
        }
        else if (recipe.get_required() > 1)
        {
            meal_list += "- " + recipe.get_name() +
                         " (" + std::to_string(recipe.get_required()) + ") " +
                         "\n";
        }
    }
    return meal_list;
}

class GroceriaOutputFrame : public frameGroceryOutput
{
public:
    using frameGroceryOutput::frameGroceryOutput;

    void appendGroceryList(std::vector<Ingredient>& ingredients,
                           std::vector<Recipe>& recipes)
    {
        textCtrlGroceryOutput->Clear();
        textCtrlGroceryOutput->AppendText(get_grocery_list(ingredients));
        textCtrlGroceryOutput->AppendText(get_meal_list(recipes));
    }

private:
    void frameGroceryOutputOnShow(wxShowEvent& event)
    {
        // appendGroceryList
    }
    void sdbSizerGroceryOutputOnOKButtonClick( wxCommandEvent& event ) { this->Destroy(); }
};


class GroceriaMainFrame : public frameMain
{
public:
    // important: this lets you easily ineheret the constructor
    using frameMain::frameMain;

private:
    // important: you are overriding the event handler functions created by wxformbuilder
    // this is where the magic happens
    const std::string recipe_file{"recipes.cfg"};
    std::string ingred_file{"ingredients.cfg"};
    std::vector<Recipe> recipes;
    std::vector<std::string> recipe_builder;
    std::vector<Ingredient> ingredients;
    const std::string grocery_list = "Test";

    void clear_stuff()
    {
            listBoxIngredients->Clear();
            listBoxRecipes->Clear();
            listBoxRestockChooser->Clear();
            listBoxRecAvailIngreds->Clear();
            listBoxRecChosenIngreds->Clear();
            listBoxRecipeChooser->Clear();
            listBoxRecipeChoices->Clear();
            listBoxRestockChoices->Clear();
            comboBoxIngredIsle->Clear();
            textCtrlIngredName->Clear();
    }


    void update_stuff()
    {
        // Sort and Populate Ingredients
        std::vector<std::string> ui_ingreds;
        for (auto &ingredient : ingredients)
        {
            if (!ingredient.deleted())
            {
                ui_ingreds.push_back(ingredient.get_name());
            }
        }

        std::sort(ui_ingreds.begin(), ui_ingreds.end());
        for (auto &ing : ui_ingreds)
        {
            listBoxIngredients->Append(ing);
            listBoxRestockChooser->Append(ing);
            listBoxRecAvailIngreds->Append(ing);
        }

        // Sort and Populate Aisles
        std::vector<std::string> ui_aisles = vect_unique_aisles(ingredients);
        for (auto &aisle : ui_aisles)
        {
            comboBoxIngredIsle->Append(aisle);
        }

        // Populate Recipes
        std::vector<std::string> ui_recipes;
        for (auto &recipe : recipes)
        {
            if (!recipe.deleted())
            {
                ui_recipes.push_back(recipe.get_name());
            }
        }
        std::sort(ui_recipes.begin(), ui_recipes.end());
        for (auto &recipe : ui_recipes)
        {
            listBoxRecipes->Append(recipe);
            listBoxRecipeChooser->Append(recipe);
        }

        // Populate Choices
        for (auto &recipe : recipes)
        {
            if (recipe.get_required() > 0)
            {
                for (int i = 0; i < recipe.get_required(); i++)
                {
                    listBoxRecipeChoices->Append(recipe.get_name());
                }
            }
        }
        for (auto &ingred : ingredients)
        {
            if (ingred.get_required() > 0)
            {
                for (int i = 0; i < ingred.get_required(); i++)
                {
                    listBoxRestockChoices->Append(ingred.get_name());
                }
            }
        }

        // Populate recipe builder
        for (auto &ingred : recipe_builder)
        {
            listBoxRecChosenIngreds->Append(ingred);
        }
    }


    void refresh_outstanding(Recipe& rec, int amount)
    {
        rec.set_outstanding(amount);
        refresh_app();
        rec.set_outstanding(0);
            // this works because the app only processes one item at a time
            // refactor required for multi-select
    }

    void refresh_app()
    {
        clear_stuff();
        update_ingredients(recipes, ingredients);
        update_stuff();
    }

    void commitRecipeChoice()
    {
        // increment the appropriate recipe
        if (listBoxRecipeChooser->GetSelection() != wxNOT_FOUND)
        {
            std::cout << "\n\nChose Recipe: " << listBoxRecipeChooser->GetString(listBoxRecipeChooser->GetSelection()) << "\n";
            for (auto &rec : recipes)
            {
                if (rec.get_name() == listBoxRecipeChooser->GetString(listBoxRecipeChooser->GetSelection()))
                {
                    rec.increment();
                    refresh_outstanding(rec, 1);
                    return;
                }
            }
        }
    }

    void removeRecipeChoice(char all_copies = 'n')
    {
        // decrement the appropriate recipe
        if (listBoxRecipeChoices->GetSelection() != wxNOT_FOUND)
        {
            std::cout << "\nRemove recipe choice: " << listBoxRecipeChoices->GetString(listBoxRecipeChoices->GetSelection()) << "\n";
            for (auto &rec : recipes)
            {
                if (rec.get_name() == listBoxRecipeChoices->GetString(listBoxRecipeChoices->GetSelection()))
                {
                    if (all_copies == 'a')
                    {
                        int amount = 0 - rec.get_required();
                        rec.increment('0');
                        refresh_outstanding(rec, amount);
                    }
                    else
                    {
                        rec.increment('-');
                        refresh_outstanding(rec, -1);
                    }
                    return;
                }
            }
        }
    }

    void commitRestockChoice()
    {
        // increment the appropriate ingredient
        if (listBoxRestockChooser->GetSelection() != wxNOT_FOUND)
        {
            std::cout << "Chose Restock: "
                      << "["
                      << listBoxRestockChooser->GetSelection()
                      << "] "
                      << listBoxRestockChooser->GetString(listBoxRestockChooser->GetSelection())
                      << "\n";
            for (auto &ingr : ingredients)
            {
                if (ingr.get_name() == listBoxRestockChooser->GetString(listBoxRestockChooser->GetSelection()))
                {
                    ingr.increment();
                    refresh_app();
                    return;
                }
            }
        }
    }

    void removeRestockChoice(char all_copies = 'n')
    {
        // decrement the appropriate recipe
        if (listBoxRestockChoices->GetSelection() != wxNOT_FOUND)
        {
            std::cout << "\nRemove restock choice: " << listBoxRestockChoices->GetString(listBoxRestockChoices->GetSelection()) << "\n";
            for (auto &ingr : ingredients)
            {
                if (ingr.get_name() == listBoxRestockChoices->GetString(listBoxRestockChoices->GetSelection()))
                {
                    if (all_copies == 'a')
                    {
                        ingr.increment('0');
                    }
                    else
                    {
                        ingr.increment('-');
                    }
                    refresh_app();
                    return;
                }
            }
        }
    }

    void resetChoices()
    {
        for (auto &ingr : ingredients)
        {
            ingr.increment('0');
        }
        for (auto &rec : recipes)
        {
            rec.increment('0');
        }
        refresh_app();
    }

    void commitRecIngred()
    {
        std::cout << "\n(Recipe builder) ingredient added: " << listBoxRecAvailIngreds->GetStringSelection();
        recipe_builder.push_back(listBoxRecAvailIngreds->GetStringSelection().ToStdString());
        refresh_app();
        return;
    }

    void removeRecIngred()
    {
        std::cout << "\n(Recipe builder) ingredient removed: " << listBoxRecChosenIngreds->GetStringSelection();
        recipe_builder.erase(std::remove(recipe_builder.begin(), recipe_builder.end(), listBoxRecChosenIngreds->GetStringSelection()), recipe_builder.end());
        refresh_app();
        return;
    }

    void process_recipe_fields(const bool del=false)
    {
        // Get recipe name from the recipe builder form
        const std::string reci_name = textCtrlReciName->GetValue().ToStdString();
        
        int ingred_id;

        if (reci_name == "") { return; }
        for (auto &reci : recipes)
        {
            if (reci.get_name() == reci_name)
            {
                if (del)
                {
                    reci.set_del(true);
                    std::cout << "Deleted " << reci.get_name() << "\n";
                    return;
                }
                else
                {
                    reci.clear_ingreds();
                    for (auto &ing : recipe_builder)
                    {
                        ingred_id = find_item_id(ingredients, ing);
                        reci.add_ingred(ingred_id);
                    }
                    return;
                }
            }
        }
        // if not existing create new
        int new_id = recipes.size();
        recipes.push_back({new_id, reci_name});
        for (auto &ing : recipe_builder)
        {
            const int ingred_id = find_item_id(ingredients, ing);
            recipes.back().add_ingred(ingred_id);
        }
        std::cout << "Added new recipe: " << reci_name << "\n";
    }

    void process_ingredient_fields(const bool del=false)
    {
        // Get all the fields from the ingredients form
        const std::string aisle = comboBoxIngredIsle->GetValue().ToStdString();
        const std::string ingred_name = textCtrlIngredName->GetValue().ToStdString();
    
        if (ingred_name == "") { return; }
        for (auto &ing : ingredients)
        {
            if (ing.get_name() == ingred_name)
            {
                if (del)
                {
                    ing.set_del(true);
                    std::cout << "Deleted " << ing.get_name() << "\n";
                    return;
                }
                else
                {
                    ing.set_aisle(aisle);
                    ing.set_del(false);
                    std::cout << "Re-added/Updated aisle to " << ing.get_aisle() << " for " << ing.get_name() << "\n";
                    return;
                }
            }
        }
        // if not existing create new
        int new_id = ingredients.size();
        ingredients.push_back({new_id, ingred_name, aisle});  // TODO Test
        std::cout << "Added new ingredient: " << ingred_name << "\n";
    }


    void frameMainOnShow(wxShowEvent& event)
    {
        parse_prefs(ingredients, recipes, recipe_file, ingred_file);
        
        // test_scenario(recipes, ingredients);
        // update_ingredients(recipes, ingredients);

        demo_pref_vect(recipes, "Recipes");
        demo_pref_vect(ingredients, "Ingredients");
        // demo_recipe_ingreds(recipes, "Recipe to Ingredients");
        // std::sort(ingredients.begin(), ingredients.end());
        // std::cout << "\n\n";
        // std::cout << get_grocery_list(ingredients);
        // std::cout << "\n";
        update_stuff();
    }
    void buttonSelectRecipeChooserOnButtonClick( wxCommandEvent& event )
    {
        commitRecipeChoice();
    }
    void buttonRemoveRecipeChooserOnButtonClick( wxCommandEvent& event )
    {
        removeRecipeChoice();
    }
    void listBoxRecipeChooserOnListBoxDClick(wxCommandEvent &event)
    {
        commitRecipeChoice();
    }
    void listBoxRecipeChoicesOnListBoxDClick( wxCommandEvent& event )
    {
        removeRecipeChoice();
    }
    void buttonRemoveCopiesRecipeChooserOnButtonClick( wxCommandEvent& event )
    {
        removeRecipeChoice('a');
    }
    void buttonSelectIngredChooserOnButtonClick( wxCommandEvent& event )
    {
        commitRestockChoice();
    }
    void listBoxRestockChooserOnListBoxDClick( wxCommandEvent& event )
    {
        commitRestockChoice();
    }
    void buttonRemoveIngredChooserOnButtonClick( wxCommandEvent& event )
    {
        removeRestockChoice();
    }
    void listBoxRestockChoicesOnListBoxDClick( wxCommandEvent& event )
    {
        removeRestockChoice();
    }
    void buttonRemoveCopiesIngredChooserOnButtonClick( wxCommandEvent& event )
    {
        removeRestockChoice('a');
    }
    void buttonClearOnButtonClick( wxCommandEvent& event )
    {
        resetChoices();
    }
    void buttonGenerateOnButtonClick( wxCommandEvent& event )
    {
        GroceriaOutputFrame *OutputFrame = new GroceriaOutputFrame(NULL, wxID_ANY);
        OutputFrame->Show(true);
        OutputFrame->appendGroceryList(ingredients, recipes);
    }
    void listBoxIngredientsOnListBoxDClick( wxCommandEvent& event )
    {
        const std::string selection = listBoxIngredients->GetStringSelection().ToStdString();
        textCtrlIngredName->SetValue(selection);
        comboBoxIngredIsle->SetValue(get_aisle_from_name(ingredients, selection));
    }
    void buttonIngredSaveOnButtonClick( wxCommandEvent& event )
    {
        process_ingredient_fields();
        write_prefs(ingredients, recipes, recipe_file, ingred_file);
        refresh_app();
    }
    void buttonIngredDeleteOnButtonClick( wxCommandEvent& event )
    {
        process_recipe_fields(true);
        write_prefs(ingredients, recipes, recipe_file, ingred_file);
        refresh_app();
    }
    void buttonRecSaveOnButtonClick( wxCommandEvent& event )
    {
        process_recipe_fields();
        write_prefs(ingredients, recipes, recipe_file, ingred_file);
        recipe_builder.clear();
        textCtrlReciName->Clear();
        refresh_app();
    }
    void buttonRecDeleteOnButtonClick( wxCommandEvent& event )
    {
        process_recipe_fields(true);
        write_prefs(ingredients, recipes, recipe_file, ingred_file);
        refresh_app();
    }
    void listBoxRecipesOnListBoxDClick( wxCommandEvent& event )
    {
        recipe_builder.clear();
        const std::string selection = listBoxRecipes->GetStringSelection().ToStdString();
        textCtrlReciName->SetValue(selection);
        std::vector<int> selection_ingreds = recipes[find_item_id(recipes, selection)].get_ingreds();
        for (auto &ing_id : selection_ingreds)
        {
            recipe_builder.push_back(get_ingredient_from_id(ingredients, ing_id));
        }
        refresh_app();
    }
    void listBoxRecAvailIngredsOnListBoxDClick( wxCommandEvent& event )
    {
        commitRecIngred();
    }
    void listBoxRecChosenIngredsOnListBoxDClick( wxCommandEvent& event )
    {
        removeRecIngred();
    }

    // TODO method for loading... or do we need a constructor?
};


// this is standard wx usage as defined in wx docs
// in short you are extending the wxApp class with your customizations
class GroceriaApp : public wxApp
{
public:
    virtual bool OnInit();
};


// standard wx to get going
wxIMPLEMENT_APP(GroceriaApp);


// also part of standard wx usage but we are using our derived frame
// it's a chain of derived classes, wx(standard wx) > MainFrame(by wxformbuilder) > MyFrame(own usage)
bool GroceriaApp::OnInit()
{
    // wxFrame *GroceriaFrame = new GroceriaMainFrame(NULL, wxID_ANY, argv[0]);
    // GroceriaFrame->Show(true);
    GroceriaMainFrame *GroceriaFrame = new GroceriaMainFrame{NULL, wxID_ANY, argv[0]};
    GroceriaFrame->Show(true);
    return true;
};