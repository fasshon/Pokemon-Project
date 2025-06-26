#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>

struct Pokemon
{
	std::string Name;

	int health;

	std::string Abilty1Name, Abilty2Name, Abilty3Name, UltName;
	int Ability1, Ability2, Ability3, ult;

	int ultcharge;
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


//Vector where i will store all the attacking pokemons stuff
std::vector<Pokemon> AttackingPokemon = {};

//This is a int that will store the index in PersonalPokemon of the three pokemon the user wants to use
std::vector<int> PersonalDeck = {};



//the two pokemon decleration
Pokemon Personal;
Pokemon Random;



void CreatePersonalPokemon();
void GenerateAttackingPokemon();
void fight();
void PlayerTurn();
int EffectivityOfAttack();
void AttackBot(int Damage);
void AttackPlayer(int Damage);

int main()
{
	CreatePersonalPokemon();
	GenerateAttackingPokemon();

	fight();

}


void CreatePersonalPokemon()
{
	std::cout << "Creating Pokemon (try not to make them too overpowered :) )" << std::endl;
	std::cout << "Health: ";
	std::cin >> Personal.health;
	std::cout << std::endl;


	std::cout << "Ability 1 damage: " << std::endl;
	std::cin >> Personal.Ability1;
	std::cout << "Ability 1 Name: ";
	std::cin >> Personal.Abilty1Name;
	std::cout << std::endl;

	

	std::cout << "Ability 2 damage: " << std::endl;
	std::cin >> Personal.Ability2;
	std::cout << std::endl;
	std::cout << "Ability 2 Name: ";
	std::cin >> Personal.Abilty2Name;
	std::cout << std::endl;
	


	std::cout << "Ability 3 damage: " << std::endl;
	std::cin >> Personal.Ability3;
	std::cout << std::endl;
	std::cout << "Ability 3 Name: ";
	std::cin >> Personal.Abilty3Name;
	std::cout << std::endl;


	
	std::cout << "Ult Damage: " << std::endl;
	std::cin >> Personal.Ability3;
	std::cout << std::endl;
	std::cout << "Ult Name: ";
	std::cin >> Personal.Abilty3Name;
	std::cout << std::endl;



	std::cout << "Defense: " << std::endl;
	std::cin >> Personal.Defense;
	std::cout << std::endl;


	std::cout << "Name: ";
	std::cin>>Personal.Name;
	PersonalPokemon.push_back(Personal);
}


void GenerateAttackingPokemon()
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
int BotDefenseActive = 0;


int PokemonChoice;
void fight()
{
	PlayerTurn();
};




void PlayerTurn()
{
		if (PersonalDeck.size() == 1)
	{
		std::cout <<"Using: "<< PersonalPokemon[PersonalDeck[0]].Name <<std::endl;
	}
	else
	{
		for (int i =0;i<PersonalDeck.size(); i++)
		{
			std::cout <<"("<<i<<"): " << PersonalPokemon[PersonalDeck[i]].Name<<std::endl;
		}
		std::cout<<"Pokemon to use: ";
		std::cin>>PokemonChoice;
		if (PokemonChoice > PersonalDeck.size())
		{
			std::cout << "Unable to use that pokemon try again"<<std::endl;
			fight();
		}
	}
	Pokemon ChossenPokemon = PersonalPokemon[PersonalDeck[PokemonChoice]];
	std::cout << "Attack (1) || Defend (0)" << std::endl;
	std::cin>>attack;
	if (attack==0)
	{
		std::cout << "How much defense do you want to use | You have: (" << Personal.Defense <<") |: ";
		std::cin >> DefenseActive;
		if (Personal.Defense>DefenseActive)
		{
			std::cout << "You cannot use that much defense" << std::endl;
			fight();
		}
		Personal.Defense = Personal.Defense-DefenseActive; 
	}
	else if (attack==1)
	{	
		int AttackChoice;
		std::cout << "You are attacking";
		std::cout << "Ability (1) | ("<<ChossenPokemon.Ability1<<")";
		std::cout << "Ability (2) | ("<<ChossenPokemon.Ability2<<")";
		std::cout << "Ability (3) | ("<<ChossenPokemon.Ability3<<")";
		if (PersonalPokemon[PersonalDeck[PokemonChoice]].ultcharge>=100)
		{
			std::cout << "ULT (4) | ("<<PersonalPokemon[PersonalDeck[PokemonChoice]].ult<<")"<<std::endl;
		}
		else
		{
			std::cout << "ULT (X) | ("<<PersonalPokemon[PersonalDeck[PokemonChoice]].ultcharge<<")"<<std::endl;
		}
		std::cout << "Choice: ";
		std::cin>>AttackChoice;

		switch (AttackChoice)
		{
		int Effective = EffectivityOfAttack();
		case 1:
		{

		
			std::cout << "Used: " << PersonalPokemon[PersonalDeck[PokemonChoice]].Abilty1Name << std::endl;

			if (Effective == 1)
			{
				std::cout << "Your attack was Good and you did " << PersonalPokemon[PersonalDeck[PokemonChoice]].Ability1 * .75 << std::endl;
			}
			else if(Effective == 2)
			{
				std::cout << "Your attack was Effective and you did " << PersonalPokemon[PersonalDeck[PokemonChoice]].Ability1 * .85 << "damage"<<std::endl;
			}
			else
			{
				std::cout << "Your attack was PERFECT and you did " << PersonalPokemon[PersonalDeck[PokemonChoice]].Ability1 << "damage"<<std::endl;
			}
			std::cout << "Attacker: " << AttackingPokemon[0].health <<std::endl;
			std::cout <<  PersonalPokemon[PersonalDeck[PokemonChoice]].Name<<": "<< PersonalPokemon[PersonalDeck[PokemonChoice]].health;
			break;
		}
		case 2:
		{
			std::cout << "Used: " << PersonalPokemon[PersonalDeck[PokemonChoice]].Abilty2Name << std::endl;

			if (Effective == 1)
			{
				std::cout << "Your attack was Good and you did " << PersonalPokemon[PersonalDeck[PokemonChoice]].Ability2 * .75 << "damage"<<std::endl;
			}
			else if(Effective == 2)
			{
				std::cout << "Your attack was Effective and you did " << PersonalPokemon[PersonalDeck[PokemonChoice]].Ability2 * .85 << "damage"<<std::endl;
			}
			else
			{
				std::cout << "Your attack was PERFECT and you did " << PersonalPokemon[PersonalDeck[PokemonChoice]].Ability2 << "damage"<<std::endl;
			}
			std::cout << "Attacker: " << AttackingPokemon[0].health <<std::endl;
			std::cout <<  PersonalPokemon[PersonalDeck[PokemonChoice]].Name<<": "<< PersonalPokemon[PersonalDeck[PokemonChoice]].health;
		}
		case 3:
		{
			std::cout << "Used: " << PersonalPokemon[PersonalDeck[PokemonChoice]].Abilty3Name << std::endl;

			if (Effective == 1)
			{
				std::cout << "Your attack was Good and you did " << PersonalPokemon[PersonalDeck[PokemonChoice]].Ability3 * .75 << "damage"<<std::endl;
			}
			else if(Effective == 2)
			{
				std::cout << "Your attack was Effective and you did " << PersonalPokemon[PersonalDeck[PokemonChoice]].Ability3 * .85 << "damage"<<std::endl;
			}
			else
			{
				std::cout << "Your attack was PERFECT and you did " << PersonalPokemon[PersonalDeck[PokemonChoice]].Ability3 << "damage"<<std::endl;
			std::cout << "Attacker: " << AttackingPokemon[0].health <<std::endl;
			std::cout <<  PersonalPokemon[PersonalDeck[PokemonChoice]].Name<<": "<< PersonalPokemon[PersonalDeck[PokemonChoice]].health;
			}
		}
		case 4:
		{
			if (PersonalPokemon[PersonalDeck[PokemonChoice]].ultcharge == 100)
			{
				std::cout << "Used: " << PersonalPokemon[PersonalDeck[PokemonChoice]].UltName << std::endl;
				std::cout << "You ulted and did: " << PersonalPokemon[PersonalDeck[PokemonChoice]].Ability3 << "damage"<<std::endl;
			}
		}
		}
	}
	PersonalPokemon[PersonalDeck[PokemonChoice]].ultcharge = PersonalPokemon[PersonalDeck[PokemonChoice]].ultcharge + 25;
	BotTurn();
}



void BotTurn()
{
	Pokemon Enemy = AttackingPokemon[0];

	if (Enemy.ultcharge >= 100)
	{
		
	}


}


int EffectivityOfAttack()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int Effectivity = (std::rand() % 100) + 1;

	
	if (Effectivity < 50)
	{
		return 1;
	}
	else if (Effectivity < 85)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}



void AttackBot(int Damage)
{
	Pokemon Enemy = AttackingPokemon[0];

	
}

void AttackPlayer(int Damage)
{

}