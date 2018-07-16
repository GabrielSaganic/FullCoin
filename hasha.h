#ifndef HASHA_H_INCLUDED
#define HASHA_H_INCLUDED

#include <iostream>
#include <sstream>
#include <bitset>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

vector<unsigned long> convert_to_binary(const string);

vector<unsigned long> pad_to_512bits(const vector<unsigned long>);

vector<unsigned long> resize_block(vector<unsigned long>);

string compute_hash(const vector<unsigned long>);

string show_as_hex(unsigned long);
void cout_block_state(vector<unsigned long>);
string show_as_binary(unsigned long);
const bool show_block_state_add_1 = 0;
const bool show_distance_from_512bit = 0;
const bool show_padding_results = false;
const bool show_working_vars_for_t = 0;
const bool show_T1_calculation = false;
const bool show_T2_calculation = false;
const bool show_hash_segments = false;
const bool show_Wt = false;

string hashing(string message);

vector<unsigned long> resize_block(vector<unsigned long> input);

void cout_block_state(vector<unsigned long> block);

string show_as_hex(unsigned long input);

string show_as_binary(unsigned long input);

vector<unsigned long> convert_to_binary(const string input);

vector<unsigned long> pad_to_512bits(vector<unsigned long> block);
string compute_hash(const vector<unsigned long> block);

#endif // HASHA_H_INCLUDED
