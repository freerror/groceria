#include <iostream>

class Ingredient {
    private:
        int id;
        string name;
        string filter;
        bool required;
    public:
        Ingredient(int id, 
                   string name, 
                   string filter, 
                   bool required = false) 
        : id(id), name(name), filter(filter),
          required(required) {}
};

class Recipe {
    private:
        int id;
        string name;
        string filter;
        string* ingredients;
        bool status;
    public:
        Recipe(int id,
               string name,
               string filter,
               string* ingredients,
               bool status = false)
        : id(id), name(name), filter(filter), 
          ingredients(ingredients), status(status) {}
};


string * getRequiredIngredients(string *items,
                               string *recipes,
                               string *ingredients,
                               string *required_ingredients) {
    // TODO Cull not needed recipe ingredients
    // TODO Get new recipe ingredients
    // TODO Cull ingredient items
    // TODO Add ingredient items
    // TODO return required ingredients
}

/* TODO Method Restore bool selection
 * 
 * bool_list
 * flat_list
 * 
 */

/* TODO Learn about Vectors and use those instead of multi-dimensional arrays
 *
 */

/* TODO Method Make Grocery List
 * 
 * ingredients
 * item choices
 * restock ingredients
 * 
 */


/* TODO Method Main/Session
 * 
 * ingredients
 * recipes
 * required_ingredients
 * 
 */