#pragma once
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

#define EXIT 4
#if _WIN32
#define CLEAR system("cls")
#elif __linux__
#define CLEAR system("clear")
#endif