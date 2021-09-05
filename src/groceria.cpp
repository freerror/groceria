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


// Inheret own class from the one generated by wxformbuilder
class Item
{
public:
    Item(int id, std::string name)
        : id(id), name(name)
    {
        this->required_count = 0;
    }

    // mutators
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
};


class Ingredient : public Item
{
public:
    Ingredient(int id, std::string name, std::string isle) : Item(id, name)
    {
        this->isle = isle;
    }

    std::string get_isle()
    {
        return this->isle;
    }

private:
    std::string isle;
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

    void add_ingred(int& ingred)
    {
        ingredients.push_back(ingred);
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

// TODO Alternative to this function using algorithm
int find_ingredient_id(std::vector<Ingredient> &ingredients, std::string name)
{
    for (auto &val : ingredients)
    {
        if (name == val.get_name())
        {
            return val.get_id();
        }
    }
    return -1;
};


// TODO alternative using algorithm
template<typename T, typename O, std::size_t N>
bool in_this_array(T (&arr)[N], O &val)
{
    return std::find(std::begin(arr),
                     std::end(arr),
                     val
                    ) != std::end(arr);
};


// TODO alternative using algorithm
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

// TODO rewrite this for a database
void parse_prefs(std::vector<Ingredient>& ingredients,
                 std::vector<Recipe>& recipes,
                 const std::string& recipe_file,
                 const std::string& ingred_file)
{
    // uses the recipes.cfg to populate both recipes
    // and ingredients
    // ingredients.cfg is just used for isles
    std::ifstream recfile{recipe_file};
    std::ifstream ingfile{ingred_file};
    std::string line;
    std::string cur_isle;
    std::string cur_recipe;
    std::vector<std::string> seen_ingreds;
    std::unordered_map<std::string, std::string> conf_ingreds;  // ingreds broken down by isle
    int char_pos;
    int recipe_id = 0;
    int ingred_id = 0;
    int prev_ingred_id;
    
    // Populate ingredients with ingredients
    while (std::getline(ingfile, line, '\n'))
    {
        // isle reference
        if (line.find("#") != std::string::npos)
        {
            cur_isle = line.substr(2, line.find("/"));
        }
        else if (line.length() > 1)
        {
            ingredients.push_back({ingred_id, line, cur_isle});
            ingred_id++;
        }
    }

    // make recipe conf
    while (std::getline(recfile, line, '\n'))
    {
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
                }
            }
        }
        else
        {
            std::cout << "[blank line]"
                      << "\n";
        }
    }
};



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
    else
    {
        std::cout << "Nothing to do\n\n";
    }
};


void test_scenario(std::vector<Recipe>& recipes,
                   std::vector<Ingredient>& ingredients)
{
    int choices[4] = {3, 5, 21, 10};
    int cur_ingred;

    for (auto &val : recipes)
    {
        cur_ingred = val.get_id();
        if (in_this_array(choices, cur_ingred))
        {
            val.increment('+');
        }
    }
};


std::string get_grocery_list(std::vector<Ingredient>& ingredients)
{
    std::string cur_isle;
    std::string last_isle;
    std::string grocery_list = "=== GROCERY LIST ===\n\n";
    for (auto &val : ingredients)
    {
        cur_isle = val.get_isle();
        if (cur_isle == last_isle)
        {
            if (val.get_required())
            {
                if (val.get_required() > 1)
                {
                    grocery_list += "- [ ] " + val.get_name() + " (" + std::to_string(val.get_required()) + ")" + "\n";
                }
                else
                {
                    grocery_list += "- [ ] " + val.get_name() + "\n";
                }
            }
        }
        else
        {
            grocery_list += "== "
                         + cur_isle
                         + " ==\n";
        }
       last_isle = cur_isle; 
    }
    return grocery_list;
};

class GroceriaOutputFrame : public frameGroceryOutput
{
public:
    using frameGroceryOutput::frameGroceryOutput;

    void appendGroceryList(std::vector<Ingredient>& ingredients)
    {
        textCtrlGroceryOutput->Clear();
        textCtrlGroceryOutput->AppendText(get_grocery_list(ingredients));
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
    std::vector<Ingredient> ingredients;
    const std::string grocery_list = "Test";

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

    void clear_stuff()
    {
            listBoxIngredients->Clear();
            listBoxRestockChooser->Clear();
            listBoxRecAvailIngreds->Clear();
            listBoxRecipes->Clear();
            listBoxRecipeChooser->Clear();
            listBoxRecipeChoices->Clear();
            listBoxRestockChoices->Clear();
    }


    void update_stuff()
    {
        // Populate Ingredients
        for (auto &ingredient : ingredients)
        {
            listBoxIngredients->Append(ingredient.get_name());
            listBoxRestockChooser->Append(ingredient.get_name());
            listBoxRecAvailIngreds->Append(ingredient.get_name());
        }

        // Populate Recipes
        for (auto &recipe : recipes)
        {
            listBoxRecipes->Append(recipe.get_name());
            listBoxRecipeChooser->Append(recipe.get_name());
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
                if (rec.get_id() == listBoxRecipeChooser->GetSelection())
                {
                    rec.increment();
                    refresh_outstanding(rec, 1);
                    break;
                }
            }
        }
        else
        {
            // do nothing
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
                    break;
                }
            }
        }
        else
        {
            // do nothing
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
                if (ingr.get_id() == listBoxRestockChooser->GetSelection())
                {
                    ingr.increment();
                    refresh_app();
                    break;
                }
            }
        }
        else
        {
            // do nothing
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
                    break;
                }
            }
        }
        else
        {
            // do nothing
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
        // TODO Open a text box with the grocery list to copy
        GroceriaOutputFrame *OutputFrame = new GroceriaOutputFrame(NULL, wxID_ANY);
        OutputFrame->Show(true);
        OutputFrame->appendGroceryList(ingredients);
    }
    void buttonIngredSaveOnButtonClick( wxCommandEvent& event )
    {
        event.Skip();
    }
    void buttonIngredDeleteOnButtonClick( wxCommandEvent& event )
    {
        event.Skip();
    }
    void buttonRecSaveOnButtonClick( wxCommandEvent& event )
    {
        event.Skip();
    }
    void buttonRecDeleteOnButtonClick( wxCommandEvent& event )
    {
        event.Skip();
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