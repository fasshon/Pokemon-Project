#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
struct Pokemon
{
	std::string Name;

	int health;

	std::string Abilty1Name, Abilty2Name, Abilty3Name, UltName;
	int Ability1, Ability2, Ability3, ult;

	int ultcharge;
	int Defense, DefenseActive;
};

//Pokemon names for the name part dur
std::vector<std::string> PokemonNames = {
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


//Vector where i will store all the attacking pokemons stuff | this makes it easier to add it imidieatly to the player set
std::vector<Pokemon> AttackingPokemon = {};
std::vector<Pokemon> SelectedPokemon = {};

//This is a int that will store the index in PersonalPokemon of the three pokemon the user wants to use
std::vector<int> PersonalDeck = {};



//the two pokemon decleration
Pokemon Personal;
Pokemon Random;

bool SelectedPokemonBool = false;

void CreatePersonalPokemon();
void GenerateAttackingPokemon();
void fight();
void PlayerTurn();
int EffectivityOfAttack();
void BotTurn();
void MainMenu();
void SwitchPokemon(int NumberInDeck);
void AdjustDeck();
void SelectFightPokemon();


int main()
{
	CreatePersonalPokemon();

	MainMenu();

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
	PersonalDeck.push_back(0);
}


void GenerateAttackingPokemon()
{
	std::srand(time(0));
	Random.health = std::rand() % 350;
	Random.Ability1 = std::rand() % 50;
	Random.Ability2 = std::rand() % 80;
	Random.Ability3 = std::rand() % 100;
	Random.Defense = std::rand() % 100;
	Random.Name = PokemonNames[std::rand() % 99];
}




int botattack = 0;
int attack = 0;
int damage;
std::string attackname;

int DefenseActive = 0;
int BotDefenseActive = 0;


int PokemonChoice;
void fight()
{
	if (!SelectedPokemonBool)
	{
		SelectFightPokemon();
	}
	PlayerTurn();

};




void PlayerTurn()
{
	Pokemon Player = SelectedPokemon[0];

	std::cout << "Attack (1) || Defend (0)" << std::endl;
	std::cin>>attack;
	switch (attack)
	{
	case 0:
	{
		std::cout << "How much defense do you want to use | You have: (" << Personal.Defense <<") |: ";
		std::cin >> Personal.DefenseActive;
		if (Personal.Defense<Personal.DefenseActive)
		{
			std::cout << "You cannot use that much defense" << std::endl;
			fight();
		}
		Personal.Defense = Personal.Defense-Personal.DefenseActive; 
	}
	case 1:
	{	
		int AttackChoice;
		std::cout << "You are attacking";
		std::cout << "Ability (1) | ("<<Player.Ability1<<")";
		std::cout << "Ability (2) | ("<<Player.Ability2<<")";
		std::cout << "Ability (3) | ("<<Player.Ability3<<")";
		if (Player.ultcharge>=100)
		{
			std::cout << "ULT (4) | ("<<Player.ult<<")"<<std::endl;
		}
		else
		{
			std::cout << "ULT (X) | ("<<Player.ultcharge<<")"<<std::endl;
		}
		std::cout << "Choice: ";
		std::cin>>AttackChoice;

		int Effective = EffectivityOfAttack();  // Moved outside the switch it looks cleaner that way

		switch (AttackChoice)
		{
		case 1:
		{
			std::cout << "Used: " << Player.Abilty1Name << std::endl;
		
			if (Effective == 1)
				std::cout << "Your attack was Good and you did " << Player.Ability1 * 0.75 << " damage" << std::endl;
			else if (Effective == 2)
				std::cout << "Your attack was Effective and you did " << Player.Ability1 * 0.85 << " damage" << std::endl;
			else
				std::cout << "Your attack was PERFECT and you did " << Player.Ability1 << " damage" << std::endl;
			
			damage = Player.Ability1 * Effective;
			break;
		}
		case 2:
		{
			std::cout << "Used: " << Player.Abilty2Name << std::endl;
		
			if (Effective == 1)
				std::cout << "Your attack was Good and you did " << Player.Ability2 * 0.75 << " damage" << std::endl;
			else if (Effective == 2)
				std::cout << "Your attack was Effective and you did " << Player.Ability2 * 0.85 << " damage" << std::endl;
			else
				std::cout << "Your attack was PERFECT and you did " << Player.Ability2 << " damage" << std::endl;
		
			damage = Player.Ability2 * Effective;
			break;
		}
		case 3:
		{
			std::cout << "Used: " << Player.Abilty3Name << std::endl;
		
			if (Effective == 75)
				std::cout << "Your attack was Good and you did " << Player.Ability3 * 0.75 << " damage" << std::endl;
			else if (Effective == 85)
				std::cout << "Your attack was Effective and you did " << Player.Ability3 * 0.85 << " damage" << std::endl;
			else
				std::cout << "Your attack was PERFECT and you did " << Player.Ability3 << " damage" << std::endl;
			damage = Player.Ability3 * Effective;
			break;
		}
		case 4:
		{
			if (Player.ultcharge == 100)
			{
				std::cout << "Used: " << Player.UltName << std::endl;
				std::cout << "You ulted and did: " << Player.Ability3 << " damage" << std::endl;
			}
			break;
		}

		default:
			std::cout << "Invalid attack choice!" << std::endl;
		}
	}
	}
	if (AttackingPokemon[0].DefenseActive > 0)
	{
		damage = damage - AttackingPokemon[0].DefenseActive;
	}
	AttackingPokemon[0].health = AttackingPokemon[0].health - damage;
	if (AttackingPokemon[0].health <= 0)
	{
		std::cout << "CONGRATS!"<<std::endl;
		std::cout << "You have defeated the attacking pokemon."<<std::endl;
	}
	Player.ultcharge = Player.ultcharge + 25;
	BotTurn();
}



void BotTurn()
{
	Pokemon Enemy = AttackingPokemon[0];
	Pokemon Player = SelectedPokemon[0];
	
	if (Enemy.ultcharge >= 100)
	{
		std::cout << Enemy.Name << " used " << Enemy.UltName << " against you and did " << Enemy.ult << " damage."<<std::endl;
		Player.health = Player.health - Enemy.ult;
	}
	std::srand(std::time(nullptr)); 
	int FirstOption = std::rand() % 2;

	switch (FirstOption)
	{
		case 1:
			//attack
			std::srand(std::time(nullptr));
			int AttackChoice = rand()%3;
			switch (AttackChoice)
			{

				case 1:
					damage = Enemy.Ability1;
					attackname = Enemy.Abilty1Name;
				break;
				case 2:
					damage = Enemy.Ability2;
					attackname = Enemy.Abilty2Name;
				break;
				case 3:
					damage = Enemy.Ability3;
					attackname = Enemy.Abilty3Name;
				break;
			}

			float Effectivity = (EffectivityOfAttack = 75) ? .75 : (EffectivityOfAttack = 85) ? .85 : 1.00;
			int damage = damage * Effectivity;
			std::cout << Enemy.Name << " Used " << attackname << " and did " << damage << "."<<std::endl;
		break;



		case 2:
			std::srand(std::time(nullptr));
			int AmountOfDefense = srand()%Enemy.Defense();
			Enemy.DefenseActive = Enemy.DefenseActive + AmountOfDefense;
			std::cout << Enemy.Name << " used " << AmountOfDefense << " defense and now has " << Enemy.DefenseActive << " active defense" << std::endl;
		break;
	}

}


int EffectivityOfAttack()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int Effectivity = (std::rand() % 100) + 1;

	
	if (Effectivity < 50)
	{
		return 75;
	}
	else if (Effectivity < 85)
	{
		return 85;
	}
	else
	{
		return 100;
	}
}

void MainMenu()
{
	int Choice;
	std::cout << "(1): Adjust personal deck"<<std::endl;
	std::cout << "(2): Fight random pokemon"<<std::endl;
	std::cout << "(3): Walk forward"<<std::endl;

	std::cin>>Choice;

	switch (Choice)
	{
		case 1:
		    AdjustDeck();
	}
}

void AdjustDeck()
{
	int Choice0;
	for (int i=0;i<PersonalDeck.size();i++)
	{
		std::cout << PersonalPokemon[PersonalDeck[i]].Name << " | "<<i<<std::endl;
	}
	std::cout<<std::endl;
	std::cout << "(1): Remove and replace a pokemon."<<std::endl;
	std::cout << "(2): Exit"<<std::endl;;
	std::cin>>Choice0;
	switch (Choice0)
	{
	case 1:
	int WhichToReplace;
		std::cout << "Which pokemon would you like to replace?"<<std::endl;
		for (int i=0;i<PersonalDeck.size();i++)
		{
			std::cout << PersonalPokemon[PersonalDeck[i]].Name << " | "<< "("<<i<<")"<<i<<std::endl;
		}
		std::cin>>WhichToReplace;
		SwitchPokemon(WhichToReplace);
		break;
	
	default:
		break;
	}
}

void SwitchPokemon(int NumberInDeck)
{
	int ReplaceWith;
	Pokemon choosen = PersonalPokemon[PersonalDeck[NumberInDeck]];
	std::cout << choosen.Name << std::endl;
	std::cout << "    Health: " << choosen.health <<std::endl;
	std::cout << "    Ability 1 Name & Damage: " << choosen.Abilty1Name << " | " << choosen.Ability1 << std::endl; 
	std::cout << "    Ability 2 Name & Damage: " << choosen.Abilty2Name << " | " << choosen.Ability2 << std::endl; 
	std::cout << "    Ability 3 Name & Damage: " << choosen.Abilty3Name << " | " << choosen.Ability3 << std::endl; 
	std::cout << "    Ult Name & Damage: " << choosen.UltName << " | " << choosen.ult << std::endl;


	std::cout<<"\n\n\n\n"<<std::endl;

	for (int i=1;i<(PersonalPokemon.size()/3)+1;i++)
	{
		for (int j=i*3;j<(j+1);j++)
		{
			std::cout << PersonalPokemon[j].Name << "      " << PersonalPokemon[j+1].Name << "      " << PersonalPokemon[j+2].Name << std::endl;
		}
	}
	std::cout << "Replace with (enter a number): ";
	std::cin>>ReplaceWith;

	//Dummy vector to temp store the pack then replace the one the user chose 
	//there is def a easier way to do this but whatever
	std::vector<int> Dummy={};
	for (int i =0;i<PersonalDeck.size();i++)
	{
		Dummy.push_back(PersonalDeck[i]);
	}
	PersonalDeck.clear();
	for (int i =0;i<Dummy.size();i++)
	{
		if (Dummy[i] == NumberInDeck)
		{
			PersonalDeck.push_back(ReplaceWith);
		}
		else
		{
			PersonalDeck.push_back(Dummy[i]);
		}
	}
	MainMenu();
}

void SelectFightPokemon()
{
	if (PersonalDeck.size() <= 1)
	{
		std::cout << "Currently 1 pokemon in personal deck"<<std::endl;
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
		else
		{
			SelectedPokemon.push_back(PersonalPokemon[PersonalDeck[PokemonChoice]]);
			SelectedPokemonBool = true;
			
		}
	}
	
}
