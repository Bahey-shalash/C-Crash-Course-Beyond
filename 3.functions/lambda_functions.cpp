/*
 * Lambda Functions in C++
 *
 * A lambda function in C++ is an anonymous function that can be defined at the point where it is used.
 * It is often used for short snippets of code that are passed as arguments to algorithms or event handlers.
 * Lambda functions are particularly useful for:
 * 1. Inline use where defining a separate named function would be cumbersome.
 * 2. Capturing local variables from the surrounding scope.
 * 3. Creating concise function objects for use with the Standard Template Library (STL) algorithms.
 *
 * Syntax:
 * [capture](parameters) -> return_type { body }
 *
 * Components:
 * 1. Capture Clause [capture]: Defines what outside variables are available for use in the lambda.
 * 2. Parameters (parameters): Specifies the input parameters.
 * 3. Return Type -> return_type: (optional) Specifies the return type of the lambda.
 * 4. Body { body }: The function body containing the code to execute.
 *
 * Examples of practical applications:
 * - Sorting custom data types using `std::sort`.
 * - Implementing callbacks or event handlers.
 * - Passing custom predicates to STL algorithms like `std::find_if`.
 */


/*
 * Should Lambda Functions Always Be Declared with auto?
 *
 * In C++, lambda functions are typically declared using the `auto` keyword.
 * This is because the type of a lambda function is unique and unnamed, generated by the compiler.
 * Using `auto` allows the compiler to infer the correct type without the need for explicit type declaration.
 *
 * However, there are scenarios where specifying the type explicitly can be beneficial:
 * 1. `std::function`: If you need to store the lambda in a container or pass it around, you might use `std::function`.
 * 2. Template Parameters: When passing a lambda as a template argument, you might need to define a specific function type.
 *
 * Examples of using auto and std::function:
 */

#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
int main() {
    // Example 1: Using auto for lambda declaration
    auto greet = []() {
        std::cout << "Hello, World!" << std::endl;
    };
    greet(); // Output: Hello, World!

    // Example 2: Using std::function to store a lambda
    std::function<int(int, int)> add = [](int a, int b) -> int {
        return a + b;
    };
    int sum = add(3, 4);
    std::cout << "Sum: " << sum << std::endl; // Output: Sum: 7

    // Example 3: Lambda function with template
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};

    auto compare = [](int a, int b) -> bool {
        return a < b;
    };

    std::sort(numbers.begin(), numbers.end(), compare);
    std::cout << "Sorted numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Output: Sorted numbers: 1 2 5 5 6 9

    // Example 4: Using std::function with capture
    int factor = 2;
    std::function<int(int)> multiply = [factor](int x) -> int {
        return x * factor;
    };
    int result = multiply(5);
    std::cout << "Result: " << result << std::endl; // Output: Result: 10

    return 0;
}





/*
 * Explications en français:
 *
 * Une fonction lambda en C++ est une fonction anonyme qui peut être définie au point où elle est utilisée.
 * Elle est souvent utilisée pour des courts extraits de code passés en tant qu'arguments aux algorithmes ou gestionnaires d'événements.
 * Les fonctions lambda sont particulièrement utiles pour :
 * 1. Une utilisation en ligne où définir une fonction nommée séparément serait encombrant.
 * 2. Capturer des variables locales de la portée environnante.
 * 3. Créer des objets fonctionnels concis pour une utilisation avec les algorithmes de la bibliothèque standard (STL).
 *
 * Syntaxe :
 * [capture](paramètres) -> type_retour { corps }
 *
 * Composants :
 * 1. Clause de capture [capture] : Définit quelles variables externes sont disponibles pour utilisation dans la lambda.
 * 2. Paramètres (paramètres) : Spécifie les paramètres d'entrée.
 * 3. Type de retour -> type_retour : (optionnel) Spécifie le type de retour de la lambda.
 * 4. Corps { corps } : Le corps de la fonction contenant le code à exécuter.
 */
/*
 * Explications en français :
 *
 * Les fonctions lambda doivent-elles toujours être déclarées avec auto ?
 *
 * En C++, les fonctions lambda sont généralement déclarées en utilisant le mot-clé `auto`.
 * Cela est dû au fait que le type d'une fonction lambda est unique et sans nom, généré par le compilateur.
 * Utiliser `auto` permet au compilateur de déduire le type correct sans avoir besoin d'une déclaration explicite du type.
 *
 * Cependant, il existe des scénarios où spécifier explicitement le type peut être bénéfique :
 * 1. `std::function` : Si vous avez besoin de stocker la lambda dans un conteneur ou de la passer autour, vous pouvez utiliser `std::function`.
 * 2. Paramètres de modèle : Lors du passage d'une lambda comme argument de modèle, vous pourriez avoir besoin de définir un type de fonction spécifique.
 *
 * Exemples d'utilisation de auto et std::function :
 */