/*
 * Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.
 */

#include <iostream>
using namespace std;

void smallestPrimeNumbers(int n){
	
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++){

	 	if (prime[p] == true){
			
			for (int i = p * p; i <= n; i += p){
				prime[i] = false;	
			
			}
		}

	}


	for (int p = 2; p <= n; p++){
		
		if(prime[p])
			cout << p << " ";
	}
	cout << endl;

}

int main()
{
    int n = 30;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    smallestPrimeNumbers(n);
    return 0;
}
