#include <Windows.h>
#include <iostream>
#include <windows.h>
#include <cstdint>
#include <deque>
#include <thread>

#include "commonInclude.hpp"

using std::thread;

int SystemCapture(string CmdLine, string& ListStdOut, string& ListStdErr, int RetCode, string CmdRunDir = ".");
