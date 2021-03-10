// # Program Name : Prime Rangers

// # Question : You are given [L,R] you are required to determine the prime rangers in this range.The definition of prime rangers is that frequency of the smallest prime digit must be greater than or equal to the frequency of the second smallest prime digit in a number the frequency of the second smallest prime digit is greater than or equal to the frequency of the third smallest prime digit in a number and so on

// # Input format:
//  The first line contains an integer T denoting the number of test cases.
//  Next T lines contains two spaced seperated integer L and R denoting the range in which you have to find the prime rangers.

// # Output format:
//  Print the number of prime rangers 

// # Constraints :
//  1<=T<=5
//  1<=L<=R<=10^18

// # Sample Input1:
//  2
//  1 10
//  31 32

// # Sample Output1
//  7
//  1

// # Explanation:

// # testcase1:
//  the number 3 5 and 7 are not prime rangers because in these numbers frequency of 2 is 0 but the frequency of the prime number greater than 2 is 1

// # testcase2:
//  the number 32 is a prime ranger because the frequency of 2 is 1 and the frequency of 3 is 1 which satisfies the condition that the frequency of the smallest prime digit 2 is greater than equal to the frequency of the second smallest prime digit.


#include <iostream>
using namespace std;



bool findPR(int num){
	
	int count2 = 0, count3 = 0, count5 = 0, count7 = 0;
	
	while (num > 0){

	int val = num % 10;

	if (val == 2){
		count2++;
	
	}else if (val == 3){
		count3++;	

	}else if (val == 5){
		count5++;

	} else if (val == 7){
		count7++;

	}

	num = num / 10;
    }

	return ((count2 >= count3) && (count3 >= count5) && (count5 >= count7));

}



void findPrimeRanger(int l, int r){

	int pr = 0;
	bool res;

	for(int i = l; i <= r; i++){

		res = findPR(i);
		
		if (res){
			pr++;	
		}	
	}

	cout << "Number of Prime Rangers are " << pr << endl;
}





int main (){
    int n, l, r, i;
    cin >> n;
    for (i=0; i<n; i++){
        cin >> l >> r;
        findPrimeRanger(l, r);
    }
return 0;
}
