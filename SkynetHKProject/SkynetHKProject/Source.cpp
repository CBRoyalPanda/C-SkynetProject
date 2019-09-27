//A target
//A grid sized 1 - 64
//A drone hunter
//Software which is using a binary search algorithm

#include <iostream>
#include <ctime>
#include <random>

using namespace std;



int main()
{
	//Variables
	int target;
	int searchGridHighNumber = 64;
	int searchGridLowNumber = 1;
	int targetLocationPrediction = 0;
	
	

	//Generating a random number
	cout << "Placing a target within one of 64 sectors" << endl;
	srand(time(0));
	target = rand() % 64 + 1;

	cout << "The target is located at sector " << target << "." << endl;
	cout << "Skynet HK Aerial Initilizing software..." << endl;
	

	// Guessing Number
	// While the guess is not equal to the targets location, this will continue to run
	while (targetLocationPrediction != target)
	{
		cout << "Scanning Area..." << endl;
		
		//Sets the guess as the value in the middle of the min and the max
		targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		
		//If the guess is lower than the target
		//The minimum is set to the same value as the guess
		//Bassically ignoring the bottom half of the area
		if (targetLocationPrediction < target)
		{
			cout << "The targets location was higher than the prediction" << endl;
			searchGridLowNumber = targetLocationPrediction + 1;

			cout << "Minimum value changed to " << searchGridLowNumber << "." << endl;
		}

		//If the target is lower than the guess
		//Set the maximum to be the same value as the guess
		//Basically ignoring the top half of the area
		if (targetLocationPrediction > target)
		{
			cout << "The targets location was lower than the prediction" << endl;
			searchGridHighNumber = targetLocationPrediction - 1;

			cout << "Maximum value changed to " << searchGridHighNumber << "." << endl;
		}

		//If the guess is equal to the target's location then gg
		if (targetLocationPrediction == target)
		{
			cout << "The target has been found in sector " << targetLocationPrediction << "." << endl;
		}
	}
}