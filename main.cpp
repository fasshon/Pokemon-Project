#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>

struct Pokemon
{
	std::string Name;
	int health;
	int Ability1;
	int Ability2;
	int Ability3;
	int Defense;
};

//Pokemon names for the name part dur
std::vector<std::string> pokemonNames = {
    "Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon",
    "Charizard", "Squirtle", "Wartortle", "Blastoise", "Caterpie",
    "Metapod", "Butterfree", "Weedle", "Kakuna", "Beedrill",
    "Pidgey", "Pidgeotto", "Pidgeot", "Rattata", "Raticate",
    "Spearow", "Fearow", "Ekans", "Arbok", "Pikachu",
    "Raichu", "Sandshrew", "Sandslash", "Nidoran♀", "Nidorina",
    "Nidoqueen", "Nidoran♂", "Nidorino", "Nidoking", "Clefairy",
    "Clefable", "Vulpix", "Ninetales", "Jigglypuff", "Wigglytuff",
    "Zubat", "Golbat", "Oddish", "Gloom", "Vileplume",
    "Paras", "Parasect", "Venonat", "Venomoth", "Diglett",
    "Dugtrio", "Meowth", "Persian", "Psyduck", "Golduck",
    "Mankey", "Primeape", "Growlithe", "Arcanine", "Poliwag",
    "Poliwhirl", "Poliwrath", "Abra", "Kadabra", "Alakazam",
    "Machop", "Machoke", "Machamp", "Bellsprout", "Weepinbell",
    "Victreebel", "Tentacool", "Tentacruel", "Geodude", "Graveler",
    "Golem", "Ponyta", "Rapidash", "Slowpoke", "Slowbro",
    "Magnemite", "Magneton", "Farfetch’d", "Doduo", "Dodrio",
    "Seel", "Dewgong", "Grimer", "Muk", "Shellder",
    "Cloyster", "Gastly", "Haunter", "Gengar", "Onix",
    "Drowzee", "Hypno", "Krabby", "Kingler", "Voltorb"
};

//The list where you will store all the pokemon the player has caught
std::vector<Pokemon> PersonalPokemon = {};


//This is a int that will store the index in PersonalPokemon of the three pokemon the user wants to use
std::vector<int> PersonalDeck = {};



//the two pokemon decleration
Pokemon Personal;
Pokemon Random;

void CreatePersonalPokemon();
void CreateRandomPokemon();
void fight();
int main()
{
	CreatePersonalPokemon();
	CreateRandomPokemon();

	fight();

}


void CreatePersonalPokemon()
{
	std::cout << "Creating Pokemon (try not to make them too overpowered :) )" << std::endl;
	std::cout << "Health: ";
	std::cin >> Personal.health;
	std::cout << std::endl;


	std::cout << "Ability 1: " << std::endl;
	std::cin >> Personal.Ability1;
	std::cout << std::endl;

	
	std::cout << "Ability 2: " << std::endl;
	std::cin >> Personal.Ability2;
	std::cout << std::endl;
	
	std::cout << "Ability 3: " << std::endl;
	std::cin >> Personal.Ability3;
	std::cout << std::endl;

	std::cout << "Defense: " << std::endl;
	std::cin >> Personal.Defense;
	std::cout << std::endl;


	std::cout << "Name: ";
	std::cin>>Personal.Name;
	PersonalPokemon.push_back(Personal);
}


void CreateRandomPokemon()
{
	std::srand(time(0));
	Random.health = std::rand() % 350;
	Random.Ability1 = std::rand() % 50;
	Random.Ability2 = std::rand() % 80;
	Random.Ability3 = std::rand() % 100;
	Random.Defense = std::rand() % 100;
	Random.Name = pokemonNames[std::rand() % 99];
}




int botattack = 0;
int attack = 0;

int DefenseActive = 0;
void fight()
{
	std::cout << "Attack (1) || Defend (0)" << std::endl;
	std::cin>>attack;
	if (attack==0)
	{
		std::cout << "How much defense do you want to use | You have: (" << Personal.Defense <<") |: ";
		std::cin >> DefenseActive;
		Personal.Defense = Personal.Defense-DefenseActive; 
	}
	else if (attack==1)
	{	
		int AttackChoice;
		std::cout << "You are attacking";
		std::cout << "Ability 1 ("<<Personal.Ability1<<")";
		std::cout << "Ability 2 ("<<Personal.Ability2<<")";
		std::cout << "Ability 3 ("<<Personal.Ability3<<")";
		std::cout << "Choice: ";
		std::cin>>AttackChoice;
	}
}