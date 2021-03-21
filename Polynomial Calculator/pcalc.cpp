#include <iostream>
#include <fstream>
#include <string>
#include "Polynomial.hpp"
#include "Term.hpp"
#include <sstream>
using std::istringstream;
using std::ostringstream;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main( int argc, char *argv[] )
{
	
	if ( argc < 2)
	{
		cout << "Error: no input file, output file, or data given"<<endl;
		return EXIT_FAILURE;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////  CASE 1   //////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if(argc == 2)
	{
		//cout<<"I'm in case 1"<<endl;
		
		string pss1;
		string pss2;
		string operation;
		string ignoreme;
		ifstream in(argv[1]);
		
		bool KeepRead = true;
		bool DoMath = false;
		
		if(in.is_open())
		{
			
			while( KeepRead == true && !in.fail())
			{
				string pss1;
				string pss2;
				char peekCh = in.peek();
				
				
				if(peekCh != '\n' )
				{
					getline(in,pss1, ' ');
					//cout <<"pss1 is this: "<<pss1 << " !"<<endl;
					in >> operation;
					
					in.ignore();
					
					getline(in,pss2, '\n');
					//cout <<"pss2 is this: "<<pss2 << " !"<<endl;
					 
					DoMath = true;
				}
				
				
				
				
				
				if(DoMath == true)
				{
					//cout<<endl;
					//cout<<"This is what the pss1 contained: "<< pss1 <<endl;
					//cout<<"This is what the operation contained: "<< operation <<endl;
					//cout<<"This is what the pss2 contained: "<< pss2 <<endl;
					
					Polynomial p1;
					Polynomial p2;
					
					double coefficient;
					int power;
					
					
					
					istringstream p1s;
					istringstream p2s;
					
						
					
		
					p1s.str(pss1);
					
					while( !p1s.fail() )
					{
						p1s >> coefficient;
						p1s.ignore();
						p1s >> power;
						p1s.ignore();
			
						//cout<<"Polynomial 1's terms: "<<endl;
						//cout<< coefficient <<"x^"<< power <<endl;
			
						p1.insert_term( Term(coefficient, power) );
						coefficient;
						power;
					}
		
					p2s.str(pss2);
					
					//cout<<endl;
					//cout<<endl;
					//cout <<"The data is: "<< p2s.str() <<endl;
		 
					while( !p2s.fail() )
					{
					//	cout<<"I'm inside the second while loop"<<endl;
						p2s >> coefficient;
						p2s.ignore();
						p2s >> power;
						p2s.ignore();
			
						//cout<<"Polynomial 2's terms: "<<endl;
						//cout<< coefficient <<"x^"<< power <<endl;
			
						p2.insert_term( Term(coefficient, power) );
						coefficient;
						power;
					}
					//cout<<endl;
					//cout<<endl;
					//cout<<"The operation is: " << operation << endl;
		 
					if(operation == "+")
					{
						cout << p1 << " + " << p2 << " = " << p1+p2<<endl;
					}
		 
					else if(operation == "-")
					{
						cout << p1 << " - " << p2 << " = " << p1-p2<<endl;
					}
		 
					else if(operation == "*")
					{
						cout << p1 << " * " << p2 << " = " << p1*p2<<endl;
					}
		 
					else if(operation == "/")
					{
						try
						{
							cout << p1 << " / " << p2 << " = " << p1/p2<<endl;
						}
						
						catch(...)
						{
							cout <<"\nError: The divisor had a term of a negative degree!"<<endl;
							return EXIT_FAILURE;
						}	
					}
		 
					else if(operation == "%")
					{
						try
						{
							cout << p1 << " % " << p2 << " = " << p1%p2<<endl;
						}
						
						catch(...)
						{
							cout <<"\nError: The divisor had a term of a negative degree!"<<endl;
							return EXIT_FAILURE;
						}
					}						
					
					DoMath = false;
					
				}
				
				else if(peekCh == '\n')
				{
					KeepRead = false;
				}		
			}
			return EXIT_SUCCESS;
			in.close();
		}
			
		else
		{
			cout << "Error: not a valid input file"<<endl;
			return EXIT_FAILURE;
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////  CASE 2   //////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if(argc == 3)
	{
		string pss1;
		string pss2;
		string operation;
		string ignoreme;
		ifstream in(argv[1]);
		ofstream out(argv[2]);
		int count = 1;
		
		bool KeepRead = true;
		bool DoMath = false;
		
		if(in.is_open())
		{
			
			while( KeepRead == true && !in.fail())
			{
				string pss1;
				string pss2;
				char peekCh = in.peek();
				
				
				if(peekCh != '\n' )
				{
					getline(in,pss1, ' ');
					//cout <<"pss1 is this: "<<pss1 << " !"<<endl;
					in >> operation;
					
					in.ignore();
					
					getline(in,pss2, '\n');
					//cout <<"pss2 is this: "<<pss2 << " !"<<endl;
					 
					DoMath = true;
				}
				
				
				
				
				
				if(DoMath == true)
				{
					//cout<<endl;
					//cout<<"This is what the pss1 contained: "<< pss1 <<endl;
					//cout<<"This is what the operation contained: "<< operation <<endl;
					//cout<<"This is what the pss2 contained: "<< pss2 <<endl;
					
					Polynomial p1;
					Polynomial p2;
					
					double coefficient;
					int power;
					
					
					
					istringstream p1s;
					istringstream p2s;
					
						
					
		
					p1s.str(pss1);
					
					while( !p1s.fail() )
					{
						p1s >> coefficient;
						p1s.ignore();
						p1s >> power;
						p1s.ignore();
			
						//cout<<"Polynomial 1's terms: "<<endl;
						//cout<< coefficient <<"x^"<< power <<endl;
			
						p1.insert_term( Term(coefficient, power) );
						coefficient;
						power;
					}
		
					p2s.str(pss2);
					
					//cout<<endl;
					//cout<<endl;
					//cout <<"The data is: "<< p2s.str() <<endl;
		 
					while( !p2s.fail() )
					{
					//	cout<<"I'm inside the second while loop"<<endl;
						p2s >> coefficient;
						p2s.ignore();
						p2s >> power;
						p2s.ignore();
			
						//cout<<"Polynomial 2's terms: "<<endl;
						//cout<< coefficient <<"x^"<< power <<endl;
			
						p2.insert_term( Term(coefficient, power) );
						coefficient;
						power;
					}
					//cout<<endl;
					//cout<<endl;
					//cout<<"The operation is: " << operation << endl;
		 
					if(operation == "+")
					{
						out << p1 << " + " << p2 << " = " << p1+p2<<endl;
					}
		 
					else if(operation == "-")
					{
						out << p1 << " - " << p2 << " = " << p1-p2<<endl;
					}
		 
					else if(operation == "*")
					{
						out << p1 << " * " << p2 << " = " << p1*p2<<endl;
					}
		 
					else if(operation == "/")
					{
						try
						{
							out << p1 << " / " << p2 << " = " << p1/p2<<endl;
						}
						
						catch(...)
						{
							cout <<"\nError: The divisor had a term of a negative degree!"<<endl;
							return EXIT_FAILURE;
						}	
					}
		 
					else if(operation == "%")
					{
						try
						{
							out << p1 << " % " << p2 << " = " << p1%p2<<endl;
						}
						
						catch(...)
						{
							cout <<"\nError: The divisor had a term of a negative degree!"<<endl;
							return EXIT_FAILURE;
						}
					}						
					
					DoMath = false;
					
				}
				
				else if(peekCh == '\n')
				{
					KeepRead = false;
				}		
			}
			
			in.close();
			return EXIT_SUCCESS;
		}
			
		else
		{
			cout << "Error: not a valid input file"<<endl;
			return EXIT_FAILURE;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////  CASE 3   ///////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	else if(argc == 4)
	{
		//cout<<"I'm in case 3"<<endl;
		
		Polynomial p1;
		Polynomial p2;
		
		double coefficient;
		int power;
		
		istringstream p1s;
		istringstream p2s;
		
		string pss1 = argv[1];
		string operation = argv[2];
		string pss2 = argv[3];
		
		
		 p1s.str(pss1);
		
		//cout <<"The data is: "<< p1s.str() <<endl;
		
		
		while( !p1s.fail() )
		{
			p1s >> coefficient;
			p1s.ignore();
			p1s >> power;
			p1s.ignore();
			
			//cout<<"Polynomial 1's terms: "<<endl;
			//cout<< coefficient <<"x^"<< power <<endl;
			
			p1.insert_term( Term(coefficient, power) );
			
		}
		
		 p2s.str(pss2);
		// cout<<endl;
		 //cout<<endl;
		// cout <<"The data is: "<< p2s.str() <<endl;
		 
		while( !p2s.fail() )
		{
			//cout<<"I'm inside the second while loop"<<endl;
			p2s >> coefficient;
			p2s.ignore();
			p2s >> power;
			p2s.ignore();
			
			//cout<<"Polynomial 2's terms: "<<endl;
			//cout<< coefficient <<"x^"<< power <<endl;
			
			p2.insert_term( Term(coefficient, power) );
			
		}
		 //cout<<endl;
		 //cout<<endl;
		 //cout<<"The operation is: " << operation << endl;
		 
		 if(operation == "+")
		 {
			 cout << p1 << " + " << p2 << " = " << p1+p2<<endl;
		 }
		 
		 else if(operation == "-")
		 {
			 cout << p1 << " - " << p2 << " = " << p1-p2<<endl;
		 }
		 
		 else if(operation == "*")
		 {
			 cout << p1 << " * " << p2 << " = " << p1*p2<<endl;
		 }
		 
		 else if(operation == "/")
		 {
			 try
			{
				cout << p1 << " / " << p2 << " = " << p1/p2<<endl;
							
			}
						
			catch(...)
			{
				cout <<"\nError: The divisor had a term of a negative degree!"<<endl;
				return EXIT_FAILURE;
							
			}	
			
		 }
		 
		 else if(operation == "%")
		 {
			try
			{
				cout << p1 << " % " << p2 << " = " << p1%p2<<endl;
							
			}
						
			catch(...)
			{
				cout <<"\nError: The divisor had a term of a negative degree!"<<endl;
				return EXIT_FAILURE;
							
			}	
		 }
			
		return EXIT_SUCCESS;
	}
	
	else if(argc > 3)
	{
		cout << "Error: too many arguments"<<endl;
		return EXIT_FAILURE;
	}
	
}	
	