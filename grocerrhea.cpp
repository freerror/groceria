#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Ingredient
{
public:
    Ingredient(int id, std::string name, std::string filter)
        : id(id), name(name), filter(filter)
    {
        required = false;
    }

    // mutators
    void toggle()
    {
        this->required = !required;
    }

    bool get_status()
    {
        return this->required;
    }

    std::string get_filter()
    {
        return this->filter;
    }

    bool get_required()
    {
        return this->required;
    }

    int get_id()
    {
        return this->id;
    }

    std::string get_name()
    {
        return this->name;
    }

    // operator overload for sorting
    bool operator < (const Ingredient& ingred) const
    {
        return (filter < ingred.filter);
    }

private:
    int id;  // could be const but need refactor overator overload
    std::string name;
    std::string filter;
    bool required = false;
};

class Recipe
{
public:
    Recipe(int id, std::string name, std::string filter)
        : id(id), name(name), filter(filter)
    {
        status = false;
    }

    // mutators
    void toggle()
    {
        this->status = !status;
    }

    void add_ingred(int& ingred)
    {
        ingredients.push_back(ingred);
    }

    // accessors
    bool get_status()
    {
        return this->status;
    }

    int get_id()
    {
        return this->id;
    }

    std::string get_name()
    {
        return this->name;
    }

    std::string get_filter()
    {
        return this->filter;
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
    
    // operator overload for sorting
    bool operator < (const Recipe& recipe) const
    {
        return (name < recipe.name);
    }

private:
    int id;
    std::string name;
    std::string filter;
    std::vector<int> ingredients;
    bool status;
};

std::string *getRequiredIngredients(std::string *items,
                                    std::string *recipes,
                                    std::string *ingredients,
                                    std::string *required_ingredients){
    // TODO Cull not needed recipe ingredients
    // TODO Get new recipe ingredients
    // TODO Cull ingredient items
    // TODO Add ingredient items
    // TODO return required ingredients
};


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


void parse_prefs(std::vector<Ingredient>& ingredients,
                 std::vector<Recipe>& recipes,
                 const std::string& recipe_file,
                 const std::string& ingred_file)
{
    std::ifstream recfile{recipe_file};
    std::ifstream ingfile{ingred_file};
    std::string line;
    std::string cur_isle;
    std::string cur_recipe;
    std::vector<std::string> seen_ingreds;
    std::unordered_map<std::string, std::string> conf_ingreds;  // ingreds broken down by isle
    std::string filter = "nil";
    int recipe_id = 1;
    int ingred_id = 1;
    int prev_ingred_id;
    
    // make ingred isle conf data
    while (std::getline(ingfile, line, '\n'))
    {
        // isle/category reference
        if (line.find("#") != std::string::npos)
        {
            cur_isle = line.substr(2);
        }
        else if (line.length() > 1)
        {
            conf_ingreds.insert({line,cur_isle});
        }
    }

    // make recipe and ingred conf
    while (std::getline(recfile, line, '\n'))
    {
        // if the line starts with # it's a new recipe name
        if (line.find("#") != std::string::npos)
        {
            cur_recipe = line.substr(2);
            std::cout << "Recipe found: " << cur_recipe << "\n";
            recipes.push_back({recipe_id, cur_recipe, filter});
            recipe_id++;
        }
        // assumed to be ingredient if more than just a blank line
        else if (line.length() > 1)
        {
            if (std::find(seen_ingreds.begin(), seen_ingreds.end(), line) == seen_ingreds.end())
            {
                std::cout << "new ingred: " << line << "\n";
                // determine if isle filter and record in the new obj
                if (conf_ingreds.find(line) != conf_ingreds.end())
                {
                    filter = conf_ingreds[line];
                }
                seen_ingreds.push_back(line);
                ingredients.push_back({ingred_id, line, filter});
                // TODO Fix this ONLY recording id for NEW ingreds
                recipes.back().add_ingred(ingred_id);
                ingred_id++;
            }
            else
            {
                prev_ingred_id = find_ingredient_id(ingredients, line);
                recipes.back().add_ingred(prev_ingred_id);
                std::cout << "[already added " << line << "]\n";
            }
        }
        else
        {
            std::cout << "[blank line]"
                      << "\n";
        }
        filter = "nil";
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
    std::sort(vect.begin(), vect.end());
    std::cout << "\n\n" << title << "\n"
              << "============================\n\n"
              << std::left
              << std::setw(20) << "filter"
              << std::setw(5) << "id" 
              << std::setw(30) << "name" 
              << std::setw(5) << "status" 
              << "\n"
              << std::setw(20) << "-------"
              << std::setw(5) << "--" 
              << std::setw(30) << "-----" 
              << std::setw(5) << "-------" 
              << "\n";
    for (auto &val : vect)
    {
        std::cout << std::left
                  << std::setw(20) << val.get_filter()
                  << std::setw(5) << val.get_id()
                  << std::setw(30) << val.get_name()
                  << std::setw(5) << val.get_status()
                  << "\n";
    }

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


void update_ingredients(std::vector<Recipe>& recipes,
                        std::vector<Ingredient>& ingredients)
{
    std::vector<int> all_ingreds;
    std::vector<int> recipe_ingreds;
    int ing_vect_index;
    int last_val = -1;
    for (auto &val : recipes)
    {
        if (val.get_status())
        {
            std::cout << "\nRecipe added " << val.get_name();
            recipe_ingreds = val.get_ingreds();
            all_ingreds.insert(all_ingreds.end(),
                               recipe_ingreds.begin(),
                               recipe_ingreds.end());
        }
    }
    std::sort(all_ingreds.begin(), all_ingreds.end());
    std::cout << "\n\nUpdate ingredients:";
    for (auto &val : all_ingreds)
    {
        // find and update the appropriate ingredients
        ing_vect_index = find_vect_index(ingredients, val);
        ingredients[ing_vect_index].toggle();
        std::cout << "\nToggled index "
                  << ing_vect_index
                  << " found from id "
                  << val;
    }
};


void test_scenario(std::vector<Recipe>& recipes,
                   std::vector<Ingredient>& ingredients)
{
    int choices[7] = {2, 19, 20, 15, 9, 23, 6};
    int cur_ingred;

    // TODO Iterate through each chosen recipe, update statuses
    for (auto &val : recipes)
    {
        cur_ingred = val.get_id();
        if (in_this_array(choices, cur_ingred))
        {
            // TODO match and do the update
            val.toggle();
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
        cur_isle = val.get_filter();
        if (cur_isle == last_isle)
        {
            if (val.get_required())
            {
                grocery_list += "- [ ] " + val.get_name() + "\n";
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

int main()
{
    const std::string recipe_file{"recipes.cfg"};
    std::string ingred_file{"ingredients.cfg"};
    std::vector<Recipe> recipes;
    std::vector<Ingredient> ingredients;

    parse_prefs(ingredients, recipes, recipe_file, ingred_file);
    
    test_scenario(recipes, ingredients);
    update_ingredients(recipes, ingredients);

    demo_pref_vect(recipes, "Recipes");
    demo_pref_vect(ingredients, "Ingredients");
    demo_recipe_ingreds(recipes, "Recipe to Ingredients");
    std::sort(ingredients.begin(), ingredients.end());
    std::cout << "\n\n";
    std::cout << get_grocery_list(ingredients);
    std::cout << "\n";
}