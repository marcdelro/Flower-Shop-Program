#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

struct Flowers {
    string type;
    float price;
    int stock;
    int sales;
};

struct List {
    string orders;
    int count;
    int number;
    List* next;
};

int n = 0, total;
List* x = NULL;
List* t = NULL;
List* h = NULL;
Flowers f[10];
string flowers;
const char* flower[10] = {"Peonies", "Cockscomb", "Tulips", "RedRoses", "WhiteRoses", "SunFlower", "Daisies", "Lilies", "Carnations", "Hyacinth"};
int price[10] = {100, 145, 100, 50, 69, 150, 80, 140, 120, 85};
int stock[10] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50};

void order();
void del();
void alldel();
void items();
void check();
void best();
void checkout();
void generateReceipt();

int main() {
    int opt;
    
     List* cartItem = h;

    for (int i = 0; i < 10; i++) {
        f[i].type = flower[i];
        f[i].price = price[i];
        f[i].stock = stock[i];
        f[i].sales = 0;
    }
	cout << endl;
    cout << "  ######################################################" << endl;
    cout << "  #                                                    #" << endl;
    cout << "  #    WELCOME TO BURGEONING BEAUTY FLOWER BOUTIQUE    #" << endl;
    cout << "  #                                                    #" << endl;
    cout << "  ######################################################" << endl;
    cout << "\n  How can we help you today?"<<endl;
    cout << "\n  Press enter to continue...";
    cin.get();
    system("cls");
	
    while (true) {
    	cout << endl;
		cout << "  ###################################" << endl;
    	cout << "  #                                 #" << endl;
    	cout << "  #            Main Menu            #" << endl;
   		cout << "  #                                 #" << endl;
   		cout << "  ###################################" << endl;
        cout << "\n  [1] Place an order\n  [2] Check product availability\n  [3] List of flowers\n  [4] Best Selling Flower\n  [5] Cart\n  [6] Exit" << endl;
        cout << "\n  -------------------------------------" << endl;
		cout << "\n  Enter your option: ";
        cin >> opt;
        
        while (true) {
            if (!cin) {
                cin.clear();
                cout << "  Only enter a number within the menu: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> opt;
                continue;
            }
            else break;
        }

        switch (opt) {
        case 1:
            if (n != 0) {
                t = h;
                while (t->next != NULL) {
                    t = t->next;
                }
                x = new List;
            }
            system("cls");
            order();
            break;
        case 2:
            // Availability
            system("cls");
            check();
            break;
        case 3:
            // List
            system("cls");
            items();
            break;
        case 4:
            // Best Sellers
            system("cls");
            best();
            break;
        case 5:
            // Cart Check (Delete or Check out)
            
            system("cls");
            int i;
            if(n == 0){
            	cout<<endl;
				cout << "  ##############################" << endl;
    			cout << "  #                            #" << endl;
    			cout << "  #     Your cart is empty!    #" << endl;
    			cout << "  #                            #" << endl;
    			cout << "  ##############################" << endl;
            	cin.ignore();
            	cout << "\n  Press enter to exit...";
            	cin.get();
            	system("cls");
            	break;
			}
            cout<<endl;
			cout << "  ##############################" << endl;
    		cout << "  #                            #" << endl;
    		cout << "  #     Items in the cart:     #" << endl;
    		cout << "  #                            #" << endl;
    		cout << "  ##############################" << endl<<endl;
            cartItem = h; 
            while (cartItem != NULL) {
            	for (i = 0; i < 10; i++){
        			if (f[i].type == cartItem->orders){
						break;	
					}
        		}
                cout <<"   "<< cartItem->orders << ": " << cartItem->number << "   " << cartItem->number * f[i].price << " PHP" << endl;
                total += cartItem->number * f[i].price;
                
                cartItem = cartItem->next;
    		}
    		cout<<"\n  Total prices: "<<total<<" PHP"<<endl;
    		total = 0;
    		
    		char cartOption;
    		cout << "\n  Do you want to delete items from the cart, proceed to checkout, or go back to main menu? (D for delete, C for checkout, E for exit): ";
    		while (!(cin >> cartOption) || (cartOption != 'D' && cartOption != 'd' && cartOption != 'E' && cartOption != 'e' && cartOption != 'C' && cartOption != 'c')) {
        		cout << "\n  Invalid option. Please enter D, C, OR E: ";
        		cin.clear();
        		cin.ignore(numeric_limits<streamsize>::max(), '\n');
    		}
			
    		if (cartOption == 'D' || cartOption == 'd') {
        	// Delete items from the cart
    			if (h == NULL) {
        		cout<<endl;
				cout << "  ##############################" << endl;
    			cout << "  #                            #" << endl;
    			cout << "  #     Your cart is empty!    #" << endl;
    			cout << "  #                            #" << endl;
    			cout << "  ##############################" << endl;
   				}
					cout<<"\n  Do you want to choose what to delete or delete all? (Refer to the choices below) "<<endl;
					cout<<"\n  [1] Delete All\n  [2] Choose"<<endl;
					cout<<"\n  Enter your choice: ";
					cin>>opt;
					
					while (true) {
        			    if (!cin) { 
							cin.clear();
              	  			cout << "  Only enter a number within the menu: ";
                			cin.ignore(numeric_limits<streamsize>::max(), '\n');
                			cin >> opt;
                			continue;
            			}
            			else break;
        				}
					
					switch (opt){
						case 1:
							alldel();
							system("cls");
							break;
						case 2:
							del();
							system("cls");
							break;
						default:
            				cout << "  That was not an option." << endl;
            				cout << "  Please try again." << endl;
            				cin.ignore();
            				cout << "\n  Press enter to continue...";
            				cin.get();
            				system("cls");
            				break;
					}
			}
				
			
			else if (cartOption == 'C' || cartOption == 'c') {
        	// Proceed to checkout
        	checkout();
    		}
    		
    		else if (cartOption == 'E' || cartOption == 'e'){
    			system("cls");
    			break;
			}
   			break;
        case 6:
            // Exit
            system("cls");
            cout <<endl;
    		cout << "  #############################################" << endl;
   			cout << "  #                                           #" << endl;
    		cout << "  #     Thank you for using our program...    #" << endl;
   		 	cout << "  #                                           #" << endl;
    		cout << "  #############################################" << endl;
            return 0;
        default:
            cout << "\n________________________________" << endl;
            cout << "That was not an option" << endl;
            cout << "Please try again" << endl;
            cin.ignore();
            cout << "\nPress enter to continue...";
            cin.get();
            system("cls");
        }
    }

    return 0;
}

void order() {
    char again;
    do {
        int order;
        
		cout<<endl;
		cout << "  ####################################################################" << endl;
    	cout << "  #                                                                  #" << endl;
    	cout << "  #     What would like to order? (Refer to the list of flowers):    #" << endl;
    	cout << "  #                                                                  #" << endl;
    	cout << "  ####################################################################" << endl << endl;
        
		for (int i = 0; i < 10; i++) {
            cout <<"   " << "[" << 1 + i << "]" << " " << f[i].type << endl;
        }
        cout << "\n  -------------------------------------" << endl;
        cout << "\n  Enter your order: ";
        
        while (true) {
            cin >> order;
            if (!cin) {
                cout << "\n  Only enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (order <= 0 || order > 10) {
                cout << "\n  Only enter a number based on the list: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            } else
                break;
        }

        order--;

        cout << "  How many are you ordering: ";
        int many;
        while (true) {
            cin >> many;
            if (!cin) {
                cout << "\n  Only enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (many <= 0) {
                cout << "\n  Only enter a positive number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            } else break;
        }

        if (many > f[order].stock) {
            cout << "  Error: Ordered quantity exceeds available stock for " << f[order].type << ".\n";
            cout << "  Please order within the available stock.\n";
            break;
        }

        f[order].stock -= many; 

        bool found = false;
        List* current = h;
        while (current != NULL) {
            if (current->orders == f[order].type) {
                current->number += many; 
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found) {
            if (n == 0) {
                x = new List;
                x->count = 1;
                x->orders = f[order].type;
                x->number = many;
                t = x;
                h = x;
            } else {
                x = new List;
                x->count = n + 1;
                x->orders = f[order].type;
                x->number = many;
                t->next = x;
                t = t->next;
            }
            n++;
        }

        while (true) {
            cout << "\n  Do you like to order another one? (Y/N): ";
            cin >> again;

            if (again == 'Y' || again == 'y') {
                system("cls");
                break; 
            } else if (again == 'N' || again == 'n') {
            	if (!found){
            		t->next = x;
                	x->next = NULL;
                	break;
				}
                else break; 
            } else {
                cout << "  That was not an option" << endl;
                cout << "  Please try again..." << endl;
            }
        }

    } while (again == 'Y' || again == 'y'); 
    
    cin.ignore();
    cout << "\n  Press enter to exit...";
    cin.get();
    system("cls");
}

void best(){
	int maxSales = 0;
    int bestSellerIndex = -1;

    for (int i = 0; i < 10; i++) {
        if (f[i].sales > maxSales) {
            maxSales = f[i].sales;
            bestSellerIndex = i;
        }
    }
	
    if (bestSellerIndex != -1) {
    	cout<<endl;
    	cout << "  ##############################################" << endl;
		cout << "                                                                " << endl;
		cout << "   Best Selling Product: " << f[bestSellerIndex].type << " (Sales: " << f[bestSellerIndex].sales << ")" << endl; 
		cout << "                                                                " << endl;
		cout << "  ##############################################" << endl;  
    } 
	else {
		cout<<endl;
		cout << "  ########################" << endl;
		cout << "                          " << endl;
		cout << "   No sales recorded yet. " << endl;
		cout << "                          " << endl;
		cout << "  ########################" << endl;
    }
    
    cin.ignore();
    cout << "\n  Press enter to exit...";
    cin.get();
    system("cls");
}

void check() {
    char searchAgain;

    do {
        system("cls");
        cout<<endl;
		cout << "  #################################################################################################" << endl;
    	cout << "  #                                                                                               #" << endl;
    	cout << "  #     Which flower would you like to check its availability? (Refer to the list of flowers):    #" << endl;
    	cout << "  #                                                                                               #" << endl;
    	cout << "  #################################################################################################" << endl << endl;
        for (int i = 0; i < 10; i++) {
            cout <<"   "<< "[" << 1 + i << "]" << " " << f[i].type << endl;
        }

        int flowerNumber;
        cout << "\n  -------------------------------------" << endl;
        cout << "\n  Enter the assigned number for the flower: ";

        while (!(cin >> flowerNumber) || flowerNumber <= 0 || flowerNumber > 10) {
            cout << "  Invalid input. Please enter a valid number within the range: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int index = flowerNumber - 1;
        cout<<endl;
        cout <<"  "<< f[index].type << ": " << (f[index].stock > 0 ? "Available!" : "Out of stock");

        if (f[index].stock >= 0) {
            cout << " (Stock: " << f[index].stock << ")";
        }
        cout << endl;

        while (true) {
            cout << "\n  Do you want to search again? (Y/N): ";
            cin >> searchAgain;
            if (searchAgain == 'Y' || searchAgain == 'y') {
                break;
            } else if (searchAgain == 'N' || searchAgain == 'n') {
                break;
            } else {
                cout << "  That was not an option" << endl;
                cout << "  Please try again..." << endl;
            }
        }

    } while (searchAgain == 'Y' || searchAgain == 'y');
 
    cin.ignore();
    cout << "\n  Press enter to exit...";
    cin.get();
    system("cls");
}

void del() {
    string itemToDelete;
    
    cout << "\n  Enter the name of the flower you want to delete from the cart (refer to your cart): ";
    cin >> itemToDelete;
	
    List* current = h;
    List* prev = NULL;

    while (current != NULL) {
        if (current->orders == itemToDelete) {
            
        	int quantityToDelete;
        	cout << "  Enter the quantity of " << itemToDelete << " you want to delete: ";
            cin >> quantityToDelete;
            while (true) {
            	if (!cin) {
               	 	cin.clear();
                	cout << "  Only enter a number: ";
                	cin.ignore(numeric_limits<streamsize>::max(), '\n');
                	cin >> quantityToDelete;
                	continue;
            	}
            else break;
      	  	}
			
			for (int i = 0; i < 10; i++){
				if (f[i].type == itemToDelete){
					f[i].stock += quantityToDelete;
				}        	
			}	
			
            if (quantityToDelete <= 0 || quantityToDelete > current->number) {
                cout << "  Invalid quantity." << endl;
                cin.ignore();
    			cout << "\n  Press enter to continue...";
    			cin.get();
    			system("cls");
                return;
            }

            if (quantityToDelete == current->number) {
            	n -= 1;
				if (prev == NULL) {
                    h = current->next;
                    delete current;
                    current = h;
                }
				else{
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
                
				cout << "  Item deleted from the cart: " << itemToDelete << endl;
				cin.ignore();
    			cout << "\n  Press enter to continue...";
    			cin.get();
    			system("cls");
            } 
			else{ 
                current->number -= quantityToDelete;                
                cout <<"  " << quantityToDelete << " " << itemToDelete << "(s) removed from the cart." << endl;
            	cin.ignore();
    			cout << "\n  Press enter to continue...";
    			cin.get();
    			system("cls");
			}
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "  Item not found in the cart." << endl;
    cin.ignore();
    cout << "\n  Press enter to exit...";
    cin.get();
    system("cls");
}

void items() {
	cout <<endl;
    cout << "  ##############################################################" << endl;
    cout << "  #                                                            #" << endl;
    cout << "  #     Here are the list of flowers available in our shop.    #" << endl;
    cout << "  #                                                            #" << endl;
    cout << "  ##############################################################" << endl;
    cout <<endl;
    for (int i = 0; i < 10; i++) {
            cout<<"   "<<setw(15)<<left<<f[i].type<< "| "<<setw(8)<<right<< "Php "<<setw(10)<<fixed<<setprecision(2)<<f[i].price<<endl;
    }
    
	cin.ignore();
	cout <<endl;
	cout << "  ------------------------------------------------" << endl;
    cout << "\n   Press enter to exit...";
    cin.get();
    system("cls");
    
}

void alldel(){ //delete all data
	List* current = h;
	while (current != NULL) {
        	for (int i = 0; i < 10; i++){
        		if (f[i].type == current->orders){
        			f[i].stock += current->number;
        			f[i].sales -= current->number;
					break;	
				}
        	}       
            current = current->next;
        }
	
	List* temp = new List();
	while(h != NULL){
		temp = h;
		h = h->next;
		delete(temp);
	}
	cout<<"\n  All data has been cleared"<<endl;
	n = 0;
	
	cin.ignore();
    cout << "\n  Press enter to continue...";
    cin.get();
    system("cls");
}

void generateReceipt() {
	int i;
    ofstream receiptFile("receipt.txt");
    
    if (receiptFile.is_open()) {
        receiptFile << "Receipt\n";
        List* current = h;
        float total = 0;
        
		while (current != NULL) {
        	for (i = 0; i < 10; i++){
        		if (f[i].type == current->orders){
        			f[i].sales += current->number;
					break;	
				}
        	}
        	
            receiptFile << current->orders << " - " << current->number << " pieces - " << current->number * f[i].price <<" PHP"<< endl;
            total += current->number * f[i].price;
            
            current = current->next;
        }
        
        List* temp = new List();
		while(h != NULL){
			temp = h;
			h = h->next;
			delete(temp);
		}
	
		n = 0;
        
        receiptFile << "Total: " << total <<" PHP"<< endl;
        receiptFile.close();
        cout << "  Receipt generated successfully.\n";
    } 
	
	else {
        cout << "  Unable to generate receipt. File cannot be opened.\n";
    }
    
    cin.ignore();
    cout << "\n  Press enter to exit...";
    cin.get();
    system("cls");
}

void checkout() {
	cout<<endl;
    cout << "  Checking out...\n";
    generateReceipt();
}


