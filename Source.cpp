//Muhammad_Affan_Wajid_22i-2567|Zubair_22i-2475
#include "Header.h"

int main()
{
	char temp;
	Game game;
	game.import_tree();
	while (1)
	{
		system("cls");
		cout << "Welcome to the game Menu!" << endl;
		cout << "Select from the following options: " << endl << endl;
		cout << "1.Play the game " << endl << endl;
		cout << "2.Auto Mode" << endl << endl;
		cout << "3.Show LeaderBoard" << endl << endl;
		cout << "4.Delete Leaderboard" << endl << endl;
		cout << "5.Help" << endl << endl;
		cout << "6.Exit Game" << endl << endl;
		int select;
		cin >> select;
		switch (select)
		{
			case 1:
			{
				system("cls");
				cout << "Enter your name: ";
				string name;
				cin >> name;
				cout << "Select one of the diffculties: " << endl;
				cout << "1.Easy" << setw(20) << "2.Medium" << setw(20) << "3.Hard" << endl;
				int select;
				int size_of_graphh_n_by_n = 0;
				cin >> select;
				if (select == 1)
				{
					size_of_graphh_n_by_n = 15;
				}
				else if (select == 2)
				{
					size_of_graphh_n_by_n = 23;
				}
				else if (select == 3)
				{
					size_of_graphh_n_by_n = 30;
				}
				else
				{
					continue;
				}
				//cin >> size_of_graphh_n_by_n;

				if (!(size_of_graphh_n_by_n >= 15 && size_of_graphh_n_by_n <= 30))
				{
					cout << "Wrong Size of maze entered! ";
					return 1;
				}
				//1.Setting size of map
				game.set_size(size_of_graphh_n_by_n);
				//2.Creating map,paths,obstacles,powerups
				game.create_map(size_of_graphh_n_by_n/3, size_of_graphh_n_by_n /2, size_of_graphh_n_by_n / 4);
				//3.Create Start Point
				game.create_start_point();
				//4.Create End Point
				game.create_end_point();
				//5.Create Player 
				game.create_player();
				//6.Show the map to player
				game.print_map();
				
				cout <<endl<<endl<< "Press any button to start....";
				temp = _getch();
				game.game_loop(name);
				continue;
			}

			case 2:
			{
				system("cls");
				cout << "Select one of the diffculties: " << endl;
				cout << "1.Easy" << setw(20) << "2.Medium" << setw(20) << "3.Hard" << endl;
				int select;
				int size_of_graphh_n_by_n = 0;
				cin >> select;
				if (select == 1)
				{
					size_of_graphh_n_by_n = 15;
				}
				else if (select == 2)
				{
					size_of_graphh_n_by_n = 23;
				}
				else if (select == 3)
				{
					size_of_graphh_n_by_n = 30;
				}
				else
				{
					continue;
				}

				if (!(size_of_graphh_n_by_n >= 15 && size_of_graphh_n_by_n <= 30))
				{
					cout << "Wrong Size of maze entered! ";
					return 1;
				}
				//1.Setting size of map
				game.set_size(size_of_graphh_n_by_n);
				//2.Creating map,paths,obstacles,powerups
				game.create_map(size_of_graphh_n_by_n / 3, size_of_graphh_n_by_n / 2, size_of_graphh_n_by_n / 4);
				//3.Create Start Point
				game.create_start_point();
				//4.Create End Point
				game.create_end_point();
				//5.Create Player 
				game.create_player();
				//6.Show the map to player
				game.print_map();
				
				cout << endl << endl << "Press any button to start....";
				temp = _getch();
				system("cls");
				game.shortest_path_dijkstra();
				
				system("cls");
				
				
				continue;
			}

			case 3:
			{
				system("cls");
				game.print_leaderboard();
				temp = _getch();
				continue;
			}

			case 4:
			{
				system("cls");
				cout << "Leaderboard Successfully Deleted! " << endl;
				game.delete_leaderboard();
				temp = _getch();
				continue;
			}

			case 5:
			{
				system("cls");
				game.help();
				temp = _getch();
				continue;
			}
			case 6:
			{
				exit(0);
			}
		}
	}
}