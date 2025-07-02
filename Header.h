//Muhammad_Affan_Wajid_22i-2567|Zubair_22i-2475
#pragma once
#include<iostream>
#include<iomanip>
#include<conio.h>
#include <ctime>
#include<fstream>
#include <chrono>
#include <string>
#include <cstdlib>
#include<Windows.h>
using namespace std;


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class int_Node
{
public:
	int_Node* next;
	int data;
	int weight;
	int_Node(int data)
	{
		this->data = data;
		next = NULL;
		weight = -1;
	}
	int_Node(int data, int weight)
	{
		this->data = data;
		next = NULL;
		this->weight = weight;
	}
};
class List
{
private:
	int_Node* head;
	void reverse(int_Node*& head, int_Node* curr, int_Node* prev)
	{
		if (curr == NULL)
		{
			head = prev;
			return;
		}
		reverse(head, curr->next, curr);
		curr->next = prev;
		return;
	}
public:
	List()
	{
		head = NULL;
	}
	int_Node* get_head()
	{
		return head;
	}
	int_Node*& get_head_ref()
	{
		return head;
	}
	void reverse_LL()
	{
		int_Node* curr = head;
		int_Node* prev = NULL;
		reverse(head, curr, prev);
		return;
	}
	
	void add_weight(int data, int weight)
	{
		int_Node* temp = head;
		if (temp == NULL)
		{
			head = new int_Node(data, weight);
			return;
		}
		while (temp->next)
		{
			if (temp->data != data)
			{


				temp = temp->next;
			}
			else
			{
				return;
			}
		}
		temp->next = new int_Node(data, weight);
	}
	void add(int data)//adding for adj list
	{
		int_Node* temp = head;
		if (temp == NULL)
		{
			head = new int_Node(data);
			return;
		}
		while (temp->next)
		{
			if (temp->data != data)
			{


				temp = temp->next;
			}
			else
			{
				return;
			}
		}
		temp->next = new int_Node(data);
	}
	bool in_list(int data)
	{
		int_Node* temp = head;
		while (temp)
		{
			if (temp->data == data)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	
	void print_list()
	{
		int_Node* temp = head;
		if (temp == NULL)
		{
			cout << " nothing ";
			return;
		}
		while (temp)
		{
			if (temp->weight == -1)
			{
				cout << " Vertex " << temp->data << ",";
				temp = temp->next;
			}
			else
			{
				cout << " Vertex " << temp->data << " with weight " << temp->weight << ",";
				temp = temp->next;
			}
		}
	}

	void set_weight_for_node(int num, int weight)
	{
		int_Node* temp = head;

		while (temp)
		{
			if (temp->data == num)
			{
				temp->weight = weight;
			}


			temp = temp->next;
		}
		return;
	}
	void ranomize_weight()
	{
		
		int_Node* temp = head;
		while (temp)
		{
			
			temp->weight = (1 + (rand() % 10) );
			temp = temp->next;
		}
		//Randomizes all weights for all nodes in the list]

	}
};

class Node
{
public:
	int data;
	int row;
	string type;// wall,path,turn,obstacle,powerup
	Node* next;
	List adjlist;

	Node(int data)
	{
		this->data = data;
		next = NULL;
		row = -1;
		type = "";

	}
	Node(Node& obj)//For adding objects
	{
		type = obj.type;

	}
	List get_adj_list()
	{
		return adjlist;
	}
	void give_row(int r)
	{
		row = r;
	}
	void set_type(string s)
	{
		type = s;
	}
	void add(int data)
	{
		adjlist.add(data);
	}
	void print()//Print vertice with its adjlist
	{
		cout << "Vertex " << data << " is linked to ";
		adjlist.print_list();
	}

	void print_data()
	{
		cout << data << setw(5);
	}
	void setTextColor(int colorCode) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
	}
	void print_data_type()
	{
		if (type == "")
		{
			cout << "#" << setw(5);
			
		}
		else if (type == "path")
		{
			setTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "-" << setw(5);
			setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else if (type == "turn")
		{
			cout << "+" << setw(5);
			
		}
		else if (type == "obstacle")
		{
			setTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "!" << setw(5);
			setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			
		}
		else if (type == "powerup")
		{
			setTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "*" << setw(5);
			setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			
		}
		else if (type == "start")
		{
			setTextColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "S" << setw(5);
			setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		}
		else if (type == "end")
		{
			setTextColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "E" << setw(5);
			setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		}
		else if (type == "player")
		{
			setTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "@" << setw(5);
			setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else if (type == "pathD")
		{
			setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "-" << setw(5);
			setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else if (type == "powerup2")
		{
			setTextColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "^" << setw(5);
			setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
};

class QueueNode
{
private:
	Node* front;
	Node* rear;
public:
	QueueNode()
	{
		front = NULL;
		rear = NULL;
	}

	bool isEmpty()
	{
		if(front == NULL && rear == NULL)
		{
			return true;

		}
		return false;
	}

	void Enqueue(Node* add)
	{
		if (front == NULL && rear == NULL)
		{
			front = add;
			rear = add;
			return;
		}
		else 
		{
			rear->next = add;
			rear = rear->next;
		}

	}
	void Dequeue()
	{
		if (isEmpty())
		{
			return;
		}

		if (front == rear)
		{
			front = rear = NULL;
		}
		else 
		{
			front = front->next;
		}
		
		
		return;

	}

	Node* top()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			
			return front;
		}
	}
};
class ListNode
{
private:
	Node* head;
public:
	ListNode()
	{
		head = NULL;
	}
	void add(Node* data)
	{
		Node* temp = head;
		if (temp == NULL)
		{
			head = data;
			return;
		}
		while (temp->next)
		{
			if (temp->data == data->data)
			{
				return;
			}
			temp = temp->next;
		}
		temp->next = new Node(data->data);
	}
	void add_v_in_u_weight(int data, int link, int weight)
	{
		Node* temp = head;

		while (temp)
		{
			if (temp->data == data)
			{

				temp->adjlist.add_weight(link, weight);//add the link to the list
				Node* search = new Node(link);

				return;
			}
			temp = temp->next;
		}
		return;
	}
	void add_v_in_u(int data, int link)
	{
		Node* temp = head;
		Node* search = new Node(link);

		if ((in_list(search)))
		{
			return;
		}
		while (temp)
		{
			if (temp->data == data)
			{

				temp->adjlist.add(link);//add the link to the list
				
				
				
				return;
			}
			temp = temp->next;
		}
		return;
	}

	bool in_list_data(int data)
	{
		Node* temp = head;
		while (temp)
		{
			if (temp->data == data)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool in_list(Node* data)
	{
		Node* temp = head;
		while (temp)
		{
			if (temp == data)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	void print_list()//Used to print the vertices in the list with its adjlist
	{
		Node* temp = head;
		cout << endl;
		while (temp)
		{
			temp->print();

			cout << endl;

			temp = temp->next;
		}
	}

	Node* get_node(int n)
	{
		Node* temp = head;
		
		while (temp)
		{
			if (temp->data == n)
			{
				return temp;
			}
			

			temp = temp->next;
		}
		return temp;
	}
	
	Node*& get_node_ref(int n)
	{
		Node* temp = head;

		while (temp)
		{
			if (temp->data == n)
			{
				return temp;
			}


			temp = temp->next;
		}
		return temp;
	}
	
};

class Graph
{
private:
	ListNode start;
	int size_of_map;
	string prev;
	int player_loc;
public:
	Graph()
	{
		prev = "start";
		player_loc = -1;
	}
	Graph(int n)
	{
		size_of_map = n;
		prev = "start";
		player_loc = -1;
	}
	void set_prev_default()
	{
		prev = "start";
	}
	void set_size_of_map(int n)
	{
		size_of_map = n;

	}
	void print()
	{
		start.print_list();
	}
	void reset()
	{
		start = ListNode();
		size_of_map = 0;
		prev = "start";
		player_loc = -1;
	}
	
	void generate()
	{
		int n = size_of_map ;
		int count = 0;
		//Generate a simple graph which contains all walls
		for (int i = 1; i <= n; i++)
		{
			
			for (int j = 1; j <= n; j++)
			{
				count++;
				
				Node* temp = new Node(count);//Set the Node number
				temp->row = i;//Set its row like as if it is in an array which is 2d
				
				if (!start.in_list_data(count))
				{
					start.add(temp);
				}

				//Now we add the up,down,left and right locations of the Node
				
				//For up
				if (1 <= (count - n) && (count - n) <= n * n)//Check if it is not outside the array
				{
					start.add_v_in_u(count, count - n);//Set its up connection to that node of that value if it doesnt exist it will add it automatically
				}

				//For down
				if (1 <= (count + n) && (count + n) <= n * n)//Check if it is not outside the array
				{
					start.add_v_in_u(count, count + n);//Set its up connection to that node of that value if it doesnt exist it will add it automatically
				}

				//For left
				if (1 <= (count - 1) && (count -1) <= n * n)//Check if it is not outside the array
				{
					if ((((i-1) * n)+1) <= (count -1) && (count - 1) <= (i * n))
					{
						start.add_v_in_u(count, count - 1);//Set its up connection to that node of that value if it doesnt exist it will add it automatically
					}
				}

				//For right
				if (1 <= (count + 1) && (count + 1) <= n * n)//Check if it is not outside the array
				{
					if (((i - 1) * n) <= (count + 1) && (count + 1) <= (i * n))
					{
						start.add_v_in_u(count, count + 1);//Set its up connection to that node of that value if it doesnt exist it will add it automatically
					}
				}

			}
		}
	}

	void randomize_weight()
	{
		
		
		int count = 0;
		int n = size_of_map;
		cout << setw(5);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				count++;
				start.get_node_ref(count)->adjlist.ranomize_weight();
				
			}
		
		}
	}
	void print_map()
	{
		int count = 0;
		int n = size_of_map;
		cout << setw(5);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				count++;
				start.get_node(count)->print_data_type();
			}
			cout << endl;
		}
	}

	void create_whole_map()
	{
		create_path();

	}

	void add_obstacles(int num)//it is used to add obstacles in the game after map creation and path reation
	{

		QueueNode obstacles;
		Node add(-1);
		add.set_type("obstacle");
		
		for (int i = 0; i < num; i++)//First add the obstacles in the Queue
		{
			Node* temp = new Node(add);
			obstacles.Enqueue(temp);
		}

		

		int n = size_of_map;
		int count = 0;
		while (!obstacles.isEmpty())
		{
			
			if (!obstacles.isEmpty())
			{

				count = 5;
				for (int i = 5; i <= n; i++)
				{
					for (int j = 5; j <= n; j++)
					{
						count++;
						if (start.get_node_ref(count)->type == "path")
						{
							if ((1 + (rand() % 10)) == 2)
							{
								if (!obstacles.isEmpty())
								{
									start.get_node(count)->set_type(obstacles.top()->type);

									obstacles.Dequeue();
								}
								else
								{
									return;
								}
							}

						}

					}
				}

			}
		}
	}
	void add_powerup(int num)//Here n is the number of powerups we want to add
	{
		QueueNode obstacles;
		Node add(-1);
		add.set_type("powerup");

		for (int i = 0; i < num; i++)//First add the obstacles in the Queue
		{
			Node* temp = new Node(add);
			obstacles.Enqueue(temp);
		}



		int n = size_of_map;
		int count = 0;
		while (!obstacles.isEmpty())
		{
			
			if (!obstacles.isEmpty())
			{

				count = 5;
				for (int i = 5; i <= n; i++)
				{
					for (int j = 5; j <= n; j++)
					{
						count++;
						if (start.get_node_ref(count)->type == "path")
						{
							if ((1 + (rand() % 10)) == 2)
							{
								if (!obstacles.isEmpty())
								{
									start.get_node(count)->set_type(obstacles.top()->type);

									obstacles.Dequeue();
								}
								else
								{
									return;
								}
							}

						}

					}
				}

			}
		}
	}
	void add_powerup2(int num)//Here n is the number of powerups we want to add
	{
		QueueNode obstacles;
		Node add(-1);
		add.set_type("powerup2");

		for (int i = 0; i < num; i++)//First add the obstacles in the Queue
		{
			Node* temp = new Node(add);
			obstacles.Enqueue(temp);
		}



		int n = size_of_map;
		int count = 0;
		while (!obstacles.isEmpty())
		{

			if (!obstacles.isEmpty())
			{

				count = 5;
				for (int i = 5; i <= n; i++)
				{
					for (int j = 5; j <= n; j++)
					{
						count++;
						if (start.get_node_ref(count)->type == "path")
						{
							if ((1 + (rand() % 10)) == 2)
							{
								if (!obstacles.isEmpty())
								{
									start.get_node(count)->set_type(obstacles.top()->type);

									obstacles.Dequeue();
								}
								else
								{
									return;
								}
							}

						}

					}
				}

			}
		}
	}
	void create_path()
	{
		
		while (1)
		{
			
			List in_path = dijsktra_algo();

			int_Node* temp = in_path.get_head();
			
			if (temp->next != NULL)
			{
				if (temp->next->next == NULL)
				{
					randomize_weight();
					continue;
				}
			}
			else
			{
				randomize_weight();
				continue;
			}
	
			while (temp)
			{
				/*cout << temp->data << "->";
				temp = temp->next;*/
				start.get_node(temp->data)->set_type("path");
				temp = temp->next; 
			}

			
			return;
		}
	}

	bool contains_non_visited(bool* arr)//Sees if the array contains a non -1 num indicating that the array still contains num to be visited
	{
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			if (arr[i] == false)
			{
				return true;
			}
		}
		return false;
	}
	
	int shortest_distance_node(int* distance_node)
	{
		int index = 0, min_dis;
		min_dis = INT_MAX;
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			if (min_dis > distance_node[i])
			{
				min_dis = distance_node[i];
				index = i;
			}
		}
		return index;
	}
	
	void print_list(bool* arr)
	{
		cout << endl;
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			if (arr[i] == true)
			{
				cout << "Node " << i + 1 << ":visited " << endl;
			}
			else
			{
				cout << "Node " << i + 1 << ":not visited " << endl;
			}
		}
		cout << endl;
	}
	List dijsktra_algo()
	{
		List path;
		//Think the below list as a dictionary,where array keeps track of distacne of each node using node_num - 1

		int* distance_node = new int[size_of_map* size_of_map];
		bool* visited = new bool[size_of_map* size_of_map];
		int* parent_node = new int[size_of_map * size_of_map];
		//Intitalizing values for both of them
		for (int i = 0; i < size_of_map* size_of_map; i++)
		{
			distance_node[i] = INT_MAX;
		}
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			parent_node[i] = -1;
		}


		
		int selected_node = 1;//We select here the starting or source node
		
		int_Node* temp = start.get_node(selected_node)->adjlist.get_head();// Get adjecency list head for selected node so we can traverse through adj list and get all adjecent nodes to that node
		distance_node[selected_node - 1] = 0;//Set the starting node distance to zero
		visited[selected_node - 1] = true;//True indicates that node has been visited

		//Now process the adjecent Nodes aka update their distances

		int shortest_distance = INT_MAX;
		int shortest_distance_Node = temp->data;
		while (temp)
		{
			if (visited[temp->data - 1] ==false)//We only update distance if that node has not been visited
			{
				if (distance_node[selected_node - 1] + temp->weight < distance_node[temp->data - 1])//distance of d(u) + c(u,v) < d(v)
				{
					distance_node[temp->data - 1] = distance_node[selected_node - 1] + temp->weight;//In that case update distance
					parent_node[temp->data - 1] = selected_node;//update parent node
					if (shortest_distance > distance_node[selected_node - 1] + temp->weight)
					{
						shortest_distance = distance_node[selected_node - 1] + temp->weight;
						shortest_distance_Node = temp->data;
					}
				}
			}
			temp = temp->next;
		}
		

		//int ending_node = 
		while (contains_non_visited(visited))
		{
			selected_node = shortest_distance_Node;//It first selects 1 then 2 and then so on
			
			int_Node* temp = start.get_node(selected_node)->adjlist.get_head();// Get adjecency list head for selected node so we can traverse through adj list and get all adjecent nodes to that node	
			visited[selected_node-1] = true;//-1 indicates that node has been visited

			 shortest_distance = INT_MAX;
			 shortest_distance_Node = temp->data;
			 int new_shortest_distance_Node = -1;
			//Now process the adjecent Nodes aka update their distances
			while (temp)
			{
				if (visited[temp->data - 1] ==false )//We only update distance if that node has not been visited
				{
					if (distance_node[selected_node - 1] + temp->weight < distance_node[temp->data - 1])//distance of d(u) + c(u,v) < d(v)
					{
						distance_node[temp->data - 1] = distance_node[selected_node - 1] + temp->weight;//In that case update distance
						parent_node[temp->data - 1] = selected_node;//Update parent node
					}
					if (shortest_distance > distance_node[selected_node - 1] + temp->weight)
					{
						shortest_distance = distance_node[selected_node - 1] + temp->weight;
						shortest_distance_Node = temp->data;
						new_shortest_distance_Node = temp->data;
					}
					
				}
				
				temp = temp->next;
			}
			

		//	print_list(visited);
			  if (new_shortest_distance_Node != -1) {
				selected_node = new_shortest_distance_Node;
				} else {
				    break;  
				 }


		}

		int current = size_of_map* size_of_map;//this is destination node from 1
		path.add(current);
		while (parent_node[current-1] != -1)
		{
			path.add(parent_node[current-1]);
			current = parent_node[current - 1];
		}
		return path;
	}

	
	void print_map_debug(int n) 
	{
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				count++;
				start.get_node(count)->print();
				cout << endl<<endl;
			}
			cout << endl;
		}
	}
	void set_end_point()//It sets the end point
	{
		start.get_node_ref(size_of_map*size_of_map)->set_type("end");

	}

	void set_start_point()//It sets the start point
	{
		start.get_node_ref(1)->set_type("start");
	}

	void set_player_point()//It sets the player point
	{
		start.get_node_ref(1)->set_type("player");
	}
	
	Node*& get_player()//Used to locate and return the player node
	{
		int count = 0;
		int n = size_of_map;
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				count++;
				if (start.get_node(count)->type == "player")
				{
					return start.get_node_ref(count);
				}
			}
			
		}
	}
	bool player_movement(int& score,int& time)
	{
		if (score < 0)
		{
			score = 0;
		}

		cout << endl << endl << endl << endl << endl << endl << endl;
		print_map();
		cout << endl << endl << setw(10) << "Score: " << score;
		cout << setw(size_of_map*(size_of_map-10)) << "Time Remaining: " << 300-time;
		int c = _getch();
		//Sleep(20);
		Node* player = NULL;
		if (player_loc == -1)
		{
			//player = get_player();
			player = get_player();
			player_loc = 1;
		}
		else
		{
			player = start.get_node_ref(player_loc);

		}
		if (player_loc == 1)
		{
			prev = "start";
		}
		if (c == KEY_UP) {
			int move_to_node = (player->data) - size_of_map;
			//Now we have to see if player can move up and also if it does which objects does it interact to make appropiate operations
			if (player->adjlist.in_list(move_to_node))//See if there even exists a connection
			{
				if (start.get_node_ref(move_to_node)->type == "")
				{
					
				}
				else if (start.get_node_ref(move_to_node)->type == "path")
				{
					
					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "start")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score + 50;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "obstacle")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score -5;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup2")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score * 2;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "end")
				{
					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					return true;
				}

			}
			else if(prev == "start")
			{
				prev = "start";
				system("cls");
				return false;
			}
		}
		else if (c == KEY_DOWN) {
			int move_to_node = (player->data) + size_of_map;
			//Now we have to see if player can move up and also if it does which objects does it interact to make appropiate operations
			if (player->adjlist.in_list(move_to_node))//See if there even exists a connection
			{
				if (start.get_node_ref(move_to_node)->type == "")
				{
					
				}
				else if (start.get_node_ref(move_to_node)->type == "path")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "start")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score + 50;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "obstacle")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score - 5;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup2")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score * 2;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "end")
				{
					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					return true;
				}
			}
			else if (prev == "start")
			{
				prev = "start";
				system("cls");
				return false;
			}
		}
		else if (c == KEY_LEFT) {
			int move_to_node = (player->data) -1;
			//Now we have to see if player can move up and also if it does which objects does it interact to make appropiate operations
			if (player->adjlist.in_list(move_to_node))//See if there even exists a connection
			{
				if (start.get_node_ref(move_to_node)->type == "")
				{
					
				}
				else if (start.get_node_ref(move_to_node)->type == "path")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "start")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score + 50;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "obstacle")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score - 5;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup2")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score * 2;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "end")
				{
					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					return true;
				}
			}
			else if (prev == "start")
			{
				prev = "start";
				system("cls");
				return false;
			}
		}
		else if (c == KEY_RIGHT) {
			
			int move_to_node = (player->data) +1;
			//Now we have to see if player can move up and also if it does which objects does it interact to make appropiate operations
			if (player->adjlist.in_list(move_to_node))//See if there even exists a connection
			{
				if (start.get_node_ref(move_to_node)->type == "")
				{
					
				}
				else if (start.get_node_ref(move_to_node)->type == "path")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "start")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score + 50;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "obstacle")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score - 5;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup2")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					score = score *2;
					score--;
				}
				else if (start.get_node_ref(move_to_node)->type == "end")
				{
					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					return true;
				}
			}
			else if (prev == "start")
			{
				prev = "start";
				system("cls");
				return false;
			}
		}
		prev = "path";
		system("cls");
		return false;
		
	}

	void set_node_weight_foreverynode(int Nodenum, int weight)
	{
		int count = 0;
		int n = size_of_map;
		cout << setw(5);
		for (int i = 1; i <= n; i++)//Make its weight equal to weight given in every node's adjcency list
		{
			for (int j = 1; j <= n; j++)
			{
				count++;
				
				start.get_node_ref(count)->adjlist.set_weight_for_node(Nodenum, weight);
			}

		}
	}
	void set_weights_default()
	{
		int count = 0;
		int n = size_of_map;
		cout << setw(5);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				count++;
				
				if (start.get_node_ref(count)->type == "")
				{
					//Set its value to this in all adj lists for all nodes
					set_node_weight_foreverynode(count, 1000);//Sets its weight 
					
					/*int_Node* temp = start.get_node_ref(count)->adjlist.get_head_ref();
					while (temp)
					{
						temp->weight = INT_MAX;
						temp = temp->next;
					}*/

				}
				else
				{
					set_node_weight_foreverynode(count, 5);
					/*/
					int_Node* temp = start.get_node_ref(count)->adjlist.get_head();
					while (temp)
					{
						temp->weight = INT_MAX;
						temp = temp->next;
					}*/
				}
				/*
				else if (start.get_node_ref(count)->type == "path")
				{
					set_node_weight_foreverynode(count, 5);
				}
				else if (start.get_node_ref(count)->type == "obstacle")
				{
					set_node_weight_foreverynode(count, 10);
				}
				else if (start.get_node_ref(count)->type == "powerup")
				{
					set_node_weight_foreverynode(count, 1);
				}*/
			}

		}
	}

	int shortest_distance_node1(int* distance_node, bool* visited)
	{
		int index = 32, min_dis;
		min_dis = INT_MAX;
		
			
			for (int i = 0; i < size_of_map * size_of_map; i++)
			{
				if (min_dis > distance_node[i] && visited[i] == false)
				{
					min_dis = distance_node[i];
					index = i;
				}
			}
		
		return index;
	}
	List dijsktra_algo2()//This one is used to find the shortest path
	{
		List path;
		//Think the below list as a dictionary,where array keeps track of distacne of each node using node_num - 1

		int* distance_node = new int[size_of_map * size_of_map];
		bool* visited = new bool[size_of_map * size_of_map];
		int* parent_node = new int[size_of_map * size_of_map];
		//Intitalizing values for both of them
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			distance_node[i] = INT_MAX;
		}
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			parent_node[i] = -1;
		}


		distance_node[0] = 0;//this is for starting node
		int selected_node = 0;//this is for starting node

		while (contains_non_visited(visited))
		{
			
			selected_node = shortest_distance_node1(distance_node, visited);
			visited[selected_node] = true;
			int_Node* temp = start.get_node(selected_node+1)->adjlist.get_head();// Get adjecency list head for selected node so we can traverse through adj list and get all adjecent nodes to that node	
			//Now process the adjecent Nodes aka update their distances
			while (temp)
			{
				if (visited[temp->data - 1] == false)//We only update distance if that node has not been visited
				{
					if (distance_node[selected_node ] + temp->weight < distance_node[temp->data - 1])//distance of d(u) + c(u,v) < d(v)
					{
						distance_node[temp->data - 1] = distance_node[selected_node] + temp->weight;//In that case update distance
						parent_node[temp->data - 1] = selected_node;//Update parent node
					}
					

				}

				temp = temp->next;
			}
		}

		int current = size_of_map * size_of_map-1;//this is destination node from 1
		
		while (parent_node[current] != -1)
		{
			path.add(parent_node[current ]);
			current = parent_node[current ];
		}
		return path;
	}

	int player_movement_for_path()
	{

		cout << endl << endl << endl << endl << endl << endl << endl;
		print_map();
		
	
		int c = _getch();
		//Sleep(20);
		Node* player = NULL;
		if (player_loc == -1)
		{
			//player = get_player();
			player = get_player();
			player_loc = 1;
		}
		else
		{
			player = start.get_node_ref(player_loc);

		}
		if (player_loc == 1)
		{
			prev = "start";
		}
		if (c == KEY_UP) {
			int move_to_node = (player->data) - size_of_map;
			//Now we have to see if player can move up and also if it does which objects does it interact to make appropiate operations
			if (player->adjlist.in_list(move_to_node))//See if there even exists a connection
			{
				if (start.get_node_ref(move_to_node)->type == "")
				{

				}
				else if (start.get_node_ref(move_to_node)->type == "path")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "start")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
				
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "obstacle")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup2")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "end")
				{
					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					return -1;
				}
				
			}
			else if (prev == "start")
			{
				prev = "start";
				system("cls");
				return -1;
			}
		}
		else if (c == KEY_DOWN) {
			int move_to_node = (player->data) + size_of_map;
			//Now we have to see if player can move up and also if it does which objects does it interact to make appropiate operations
			if (player->adjlist.in_list(move_to_node))//See if there even exists a connection
			{
				if (start.get_node_ref(move_to_node)->type == "")
				{

				}
				else if (start.get_node_ref(move_to_node)->type == "path")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "start")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "obstacle")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup2")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "end")
				{
					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					return -1;
				}
			}
			else if (prev == "start")
			{
				prev = "start";
				system("cls");
				return -1;
			}
		}
		else if (c == KEY_LEFT) {
			int move_to_node = (player->data) - 1;
			//Now we have to see if player can move up and also if it does which objects does it interact to make appropiate operations
			if (player->adjlist.in_list(move_to_node))//See if there even exists a connection
			{
				if (start.get_node_ref(move_to_node)->type == "")
				{

				}
				else if (start.get_node_ref(move_to_node)->type == "path")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "start")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "obstacle")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
				
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup2")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "end")
				{
					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					return -1;
				}
			}
			else if (prev == "start")
			{
				prev = "start";
				system("cls");
				return -1;
			}
		}
		else if (c == KEY_RIGHT) {

			int move_to_node = (player->data) + 1;
			//Now we have to see if player can move up and also if it does which objects does it interact to make appropiate operations
			if (player->adjlist.in_list(move_to_node))//See if there even exists a connection
			{
				if (start.get_node_ref(move_to_node)->type == "")
				{

				}
				else if (start.get_node_ref(move_to_node)->type == "path")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "start")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
				
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "obstacle")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
				
				}
				else if (start.get_node_ref(move_to_node)->type == "powerup2")
				{

					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					
				}
				else if (start.get_node_ref(move_to_node)->type == "end")
				{
					start.get_node_ref(player->data)->type = prev;//Sets the where the player was before to the its default value
					start.get_node_ref(move_to_node)->type = "player";
					player_loc = move_to_node;
					return -1;
				}
			}
			
			else if (prev == "start")
			{
				prev = "start";
				system("cls");
				return -1;
			}
		}
		else if (c == 's' || c == 'S')
		{
			//cout << player_loc << endl;
			//char temp = _getch();
			return player_loc;

			}
		prev = "path";
		system("cls");
		return -1;

	}
	List dijsktra_algo3(int start_point,int end_point)//This one is used to find the shortest path
	{
		List path;
		//Think the below list as a dictionary,where array keeps track of distacne of each node using node_num - 1

		int* distance_node = new int[size_of_map * size_of_map];
		bool* visited = new bool[size_of_map * size_of_map];
		int* parent_node = new int[size_of_map * size_of_map];
		//Intitalizing values for both of them
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			distance_node[i] = INT_MAX;
		}
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < size_of_map * size_of_map; i++)
		{
			parent_node[i] = -1;
		}


		distance_node[start_point-1] = 0;//this is for starting node
		int selected_node = start_point;//this is for starting node
		
		while (contains_non_visited(visited))
		{

			selected_node = shortest_distance_node1(distance_node, visited);
			visited[selected_node] = true;
			int_Node* temp = start.get_node(selected_node + 1)->adjlist.get_head();// Get adjecency list head for selected node so we can traverse through adj list and get all adjecent nodes to that node	
			//Now process the adjecent Nodes aka update their distances
			while (temp)
			{
				if (visited[temp->data - 1] == false)//We only update distance if that node has not been visited
				{
					if (distance_node[selected_node] + temp->weight < distance_node[temp->data - 1])//distance of d(u) + c(u,v) < d(v)
					{
						distance_node[temp->data - 1] = distance_node[selected_node] + temp->weight;//In that case update distance
						parent_node[temp->data - 1] = selected_node;//Update parent node
					}


				}

				temp = temp->next;
			}
		}

		int current = end_point - 1;//this is destination node from 1

		while (parent_node[current] != -1)
		{
			path.add(parent_node[current]);
			current = parent_node[current];
		}
		return path;
	}
	void path_finder()
	{
		set_weights_default();//Set all the weights to their default values
	//	print_map_debug(size_of_map);
		//char temp = _getch();
		while (1)
		{
			int start_point = -1;
			while (start_point == -1)
			{
				cout << "Select start point(Move the car to the point and Press S to Select that point)" << endl;
				start_point = player_movement_for_path();
				system("cls");
				

			}
		
			int end_point = -1;

			while (end_point == -1)
			{
				cout << "Select end point(Move the car to the point and Press S to Select that point)"<<endl;
				end_point = player_movement_for_path();
				system("cls");


			}
			
			List in_path = dijsktra_algo3(start_point,end_point);
			
			in_path.reverse_LL();
			int_Node* temp = in_path.get_head();// For printing path covered by car
			int_Node* temp2 = in_path.get_head();//For printing car moving
			/*
			if (temp->next != NULL)
			{
				if (temp->next->next == NULL)
				{
					
					continue;
				}
			}
			else
			{
				continue;
				
			}*/

			
			start.get_node(temp->data + 1)->set_type("player");
			temp = temp->next;
			system("cls");
			print_map();
			Sleep(200);
			int prev_loc = temp->data+1;
			while (temp)
			{
				system("cls");
				
					
					start.get_node(prev_loc)->set_type("pathD");
					start.get_node(temp->data + 1)->set_type("player");
					print_map();
					Sleep(200);
					prev_loc = temp->data + 1;
					temp = temp->next;
			}
			system("cls");
			start.get_node(prev_loc)->set_type("pathD");
			return;
		}
	}
};



class BSTNode//This is a node for the binary tree for scoring leaderboard which contains name and score for each player
{
public:
	string name;
	int score;
	BSTNode* left;
	BSTNode* right;
	BSTNode()
	{
		name = "";
		score = 0;
		left = NULL;
		right = NULL;
	}
	BSTNode(string name, int score)
	{
		this->name = name;
		this->score = score;
		left = NULL;
		right = NULL;
	}

};

class BST
{
private:
	BSTNode* root;
public:

	BST()
	{
		root = NULL;
	}
	void print()
	{
		int count = 0;
		cout << endl;
		cout << setw(20)  << " " << "Name" << setw(50) << " " << "Score" << endl<<endl;
		
		print_recursive(root, count);

	}
	void print_recursive(BSTNode* root,int& count)
	{
		if (root == NULL)
		{
			return;
		}
		count++;
		print_recursive(root->right, count);
		
		cout <<setw(24) << root->name<<setw(55) << root->score<<endl<<endl;
		print_recursive(root->left, count);
	}
	void insert1(string name, int score, BSTNode*& root)
	{
		if (root == NULL)
		{
			root = new BSTNode(name, score);
			return;
		}
		else if (root->score > score)
		{
			insert1(name, score, root->left);
			return;
		}
		else if (root->score < score)
		{
			insert1(name, score, root->right);
			return;
		}
	}
	void insert(string name, int score)
	{
		insert1(name, score, root);
	}
	BSTNode*& get_root()
	{
		return root;
	}
	bool search_by_name(string name)
	{
		if (search_by_name_re(name, root))
		{
			return true;
		}
		return false;
	}

	bool search_by_name_re(string name, BSTNode* root)
	{

		if (root == NULL)
		{
			
			return false;
		}
		bool curr = false, left, right;
		if (root->name == name)
		{
			curr = true;
		}
		
		left = search_by_name_re(name, root->left);
		right = search_by_name_re(name, root->right);
		return (left || right || curr);
	}
	int get_score_by_name(string name)
	{
		return get_score_by_name_re(name, root);
	}

	int get_score_by_name_re(string name, BSTNode* root)
	{

		if (root == NULL)
		{

			return -1;
		}

		int curr = -1, left = -1, right = -1;
		if (root->name == name)
		{
			
			curr = root->score;
		}
		left = get_score_by_name_re(name, root->left);
		right = get_score_by_name_re(name, root->right);
		if (curr != -1)
		{
			return curr;
		}
		
		else if (left != -1)
		{
			return left;
		}
		else if (right != -1)
		{
			return right;
		}
		return -1;
	}


	void delete_prev_record(string name)
	{
		delete_prev_record_re(name, root);
	}
	BSTNode* go_left(BSTNode* root)
	{
		if (root->left)
		{
			return go_left(root->left);
		}
		return root;
	}
	void delete_prev_record_re(string name, BSTNode*& root)
	{
		if (root == NULL)
		{

			return ;
		}
		else if (root->name == name)
		{
			//no child nodes
			if (root->left == NULL && root->right == NULL)
			{
				root = NULL;
			}
			else if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))//For single node
			{
				if (root->left != NULL && root->right == NULL)
				{
					root = root->left;
				}
				else if (root->left == NULL && root->right != NULL)
				{
					root = root->right;
				}
			}
			else//for two child nodes
			{
				BSTNode* temp = go_left(root->right);
				delete_prev_record_re(temp->name, root->right);
				root = temp;
			}
			return;
			
		}

		search_by_name_re(name, root->left);
		search_by_name_re(name, root->right);
		return;
	}
};
class Game
{
private:
	Graph g;
	int size_of_maze_game;
	int score;
	BST Leaderboard;
public:
	Game(int size)
	{
		size_of_maze_game = size;
		g.set_size_of_map(size_of_maze_game);
		score = 0;
	}
	Game()
	{
		size_of_maze_game = 0;
		g.set_size_of_map(size_of_maze_game);
		score = 0;
	}
	void set_size(int n)
	{
		size_of_maze_game = n;
		g.set_size_of_map(size_of_maze_game);
		score = 0;
	}

	void setTextColor(int colorCode) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
	}
	void help()
	{
		cout<<setw(45) << "GAME ELEMENTS" << endl << endl << endl << endl;
		
		//Walls description
		cout << "1.Walls" << setw(30) << "#" << "\t\tPlayer Cant go throught this" << endl << endl;

		
		//Paths description	
					
			cout << "2.Paths" << setw(30);
			setTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "-" ;
			setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout<< " \t\t" << "Path for player to go through" << endl << endl;

		//Obstacle description
			
				cout  << "3.Obstacles" ;
				setTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << setw(26) << "!";
				setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << " \t\t" << "-5 points" << endl << endl;
			

		
		
		//Points(powerup) description
			
				cout << "4.Points";
				setTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << setw(29) << "*";
				setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << " \t\t" << "+50 points" << endl << endl;


		//Start description

				cout << "5.Start";
				setTextColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << setw(30) << "S";
				setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << " \t\t" << "Indicates Start Point" << endl << endl;


			//End description

				cout << "6.End";
				setTextColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << setw(32) << "E";
				setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << " \t\t" << "Indicates End Point" << endl << endl;

		
				//Car description

				cout << "7.Car";
				setTextColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << setw(32) << "@";
				setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << " \t\t" << "This is the player" << endl << endl;


		
				//Shortest Path description

				cout << "8.Short Path";
				setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << setw(25) << "-";
				setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << " \t\t" << "This is the shortest path" << endl << endl;
		
		
		
				//Actual powerup

				cout << "9.PowerUp";
				setTextColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << setw(28) << "^";
				setTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << " \t\t" << "Score X 2" << endl << endl;


		
		
		
	
	}
	void create_player()
	{
		g.set_player_point();
	}
	void create_start_point()
	{
		g.set_start_point();
	}
	void create_end_point()
	{
		g.set_end_point();
	}
	void create_map(int obs,int p_up, int p_up2)
	{
		char temp;
	
		if (!(size_of_maze_game >= 15 && size_of_maze_game <= 30))
		{
			cout << "Wrong Size of maze entered! ";
			return ;
		}

		
		srand(time(0));//Used to create random numbers
		g.generate();//Generate Map



		g.randomize_weight();//Randomized all weights for all nodes to make random paths 
		int i = 0;
		cout << endl << endl << "Generating Path....." << endl;
		while (i < 5)//here 5 is num of paths
		{
			i++;
			g.create_path();
			g.randomize_weight();
		}
		cout << "Path Generated Successfully! " << endl << endl;
		g.add_obstacles(obs);//Add obstacles
		g.add_powerup(p_up);//Add powerus
		g.add_powerup2(p_up2);//add powerup type2
		
	}
	void print_map()
	{
		g.print_map();
	}

	//For exporting LeaderBoard
	void store_in_csv(fstream& f, BSTNode* root)//For storing the tree in a preorder way
	{
		if (root == NULL)
		{
			f << "~" << " "<<"~"<<" ";
			return;
		}
		f << root->name<<" " <<root->score<< " ";
		store_in_csv(f, root->left);
		store_in_csv(f, root->right);
		return;
	}
	void export_tree()
	{
		fstream filetree;
		filetree.open("LeaderBoard.txt", ios::out);
		store_in_csv(filetree, Leaderboard.get_root());
	}

	//For Importing LeaderBoard
	void store_in_filetree(fstream& f, BSTNode*& root)
	{
		string name;
		string score;
		if (!(f >> name>>score) || (name == "~" && score == "~"))
		{
			root = NULL;
			return;
		}
		int s = stoi(score);
		root = new BSTNode(name, s);
		store_in_filetree(f, root->left);
		store_in_filetree(f, root->right);
		return;
	}
	void import_tree()
	{
		fstream filetree;
		filetree.open("LeaderBoard.txt", ios::in);
		Leaderboard.get_root() = NULL;

		store_in_filetree(filetree, Leaderboard.get_root());
		
	}

	void print_leaderboard()
	{
		cout << endl << endl << endl << endl;
		cout << setw(55) << "Leaderboard" << endl << endl;
		Leaderboard.print();
		cout<<endl <<endl<< setw(62) << "Press any button to leave" << endl << endl;
	}

	void delete_leaderboard()
	{
		Leaderboard.get_root() = NULL;
		export_tree();
	}
	void shortest_path_dijkstra()
	{
		char temp;
		
		g.path_finder();
		cout << "Shortest Path Found! " << endl;
		g.print_map();
		temp = _getch();
		cout << endl << endl << "Press any button to go back....";
		g.reset();
	}
	
	void game_loop(string name)
	{
		system("cls");
		auto start = chrono::system_clock::now();
		
		auto after = chrono::system_clock::now();

		chrono::duration<double> elapsed_seconds = after - start;
		time_t end_time = chrono::system_clock::to_time_t(after);
		int elapsed_seconds_int = static_cast<int>(elapsed_seconds.count());
		g.set_prev_default();
		//The while loop is for the game loop and it runs till player finds the end of the maze
		while (!g.player_movement(score, (elapsed_seconds_int)) && (300-elapsed_seconds_int > 0))
		{
			system("cls");
			after = chrono::system_clock::now();
			elapsed_seconds = after - start;
			elapsed_seconds_int = static_cast<int>(elapsed_seconds.count());
			
		}
		system("cls");
		cout << endl << endl << endl << endl << endl << endl << endl;
		print_map();
		
		score = score +(300- elapsed_seconds_int);//score from collecting coins,time saved
		cout << endl << endl;

		//Now see if a previous score and name exists in the leadboard if so then print it
		if (Leaderboard.search_by_name(name))
		{
			if (Leaderboard.get_score_by_name(name) < score)//the cout is inside the getscore by name func
			{
				cout << "Your new highscore score is: " << score<<endl<<endl;
				
				cout << "Press any button to continue.... ";
				char temp = _getch();
				cout << endl << "Leaving in 3" << " ";
				Sleep(1000);
				cout  << "2" << " ";
				Sleep(1000);
				cout << "1" << " ";
				Sleep(1000);
				//delete prev highscore
				Leaderboard.delete_prev_record(name);
				//Insert the new player data
				Leaderboard.insert(name, score);

				//Save it in file
				remove("LeaderBoard.txt");
				export_tree();
				//Reset the game map
				g.reset();
			}
		}
		else
		{
			cout << setw(10) << "Your Score is: " << score << endl << endl;
		
			cout << "Press any button to continue.... ";
			char temp = _getch();
			cout << endl << "Leaving in 3" << " ";
			Sleep(1000);
			cout << "2" << " ";
			Sleep(1000);
			cout << "1" << " ";
			Sleep(1000);
			//Insert the new player data
			Leaderboard.insert(name, score);
			//Save it in file
			remove("LeaderBoard.txt");
			export_tree();
			//Reset the game map
			g.reset();
		}
	}
};