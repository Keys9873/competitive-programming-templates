/**
 * Author: Neal Wu
 * Date: 17 August 2023
 * Description: Much faster unordered_map using GNU pbds, paired with a hack-resistant hash function.
 * Verification: https://codeforces.com/contest/1642/submission/218073453
 * Time: O(1) update and access
 */

#include <ext/pb_ds/tree_policy.hpp>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Use mp.find(x) != mp.end() instead of mp.count(x)
template <typename K, typename V> using hash_table = __gnu_pbds::gp_hash_table<K, V, custom_hash>;
