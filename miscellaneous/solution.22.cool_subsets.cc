static const int MOD = 1000000007;
string M; //Will store string version of N.

int F[11]; // Will precalculate the factorial

// Given a bitmask D representing a set of digits, count the number of integers
// that use those digits without repetitions and are <= N.
int subProblem(int D) // Result is < 10!, which fits the Modulo.
{
    //Count the number of numbers that have the D set of digits and are
    // <= N.
    // We could easily precalculate this function but it is not necessary.
    //
    int c = __builtin_popcount(D);
    if (c < M.size()) {
        bool haszero = (D & 1);
        if (! haszero) {
            return F[c];
        } else {
            // (c-1)(c-1)!
            return (c-1) * F[c-1];
        }
    } else if (c > M.size()) {
        return 0;
    } else {
        long s = 0;
        for (int i = 0; i <= M.size(); i++) {
            // count all numbers such that the first i digits are are equal to N[0..i]
            long p = 1;
            int tem = D;
            // No leading zeros
            for (int j = 0; j < i; j++) {
                // Digit must be M[j]
                int d = M[j] - '0';
                if ( tem & (1 << d) ) {
                    tem ^= (1 << d);
                } else {
                    p = 0;
                }
            }
            int rem = __builtin_popcount(tem);
            // Digit in position i must be smaller than M[i]
            if (i < M.size()) {
                int v = 0;
                for (int d = 0; d < M[i] - '0'; d++) {
                    if ( (d == 0) && (i == 0) ) { //no leading zeroes
                        continue;
                    }
                    if ( ! (tem & (1<<d)) ) { //must be available
                        continue;
                    }
                    v++;
                }
                p *= v;
                rem--;
            }
            // multiply by rem!
            p *= F[rem];
            s += p;
        }
        return s % MOD;
    }
}

// Backtrack for all partitions:
int partition[10];
int pn = 0;

long total = 0;
int ways = 0;
void backtrack(int d)
{
    if (d == 10) {
        //We have generated the digit partition, count the number of sets that
        //follow it:
        long x = 1;
        for (int i = 0; i < pn; i++) {
            x = (x * subProblem(partition[i]) ) % MOD;
        }
        total += x;
        ways++;
    } else {
        // add to an existing partition:
        for (int i = 0; i < pn; i++) {
            partition[i] ^= (1 << d);
            backtrack(d + 1);
            partition[i] ^= (1 << d);
        }
        // add to a new partition
        partition[pn++] = (1 << d);
        backtrack(d + 1);
        pn--;

        // Add to the ignore partition (will not be used)
        backtrack(d + 1);
    }
}

int getNumber(int N)
{
    F[0] = 1;
    for (int i=1; i<= 10;i++) {
        F[i] = (F[i-1] * i) % MOD;
    }

    M = to_string(N);

    backtrack(0);
    cout << ways << " partitions found"<<endl;
    return (total + MOD - 1) % MOD;
}
