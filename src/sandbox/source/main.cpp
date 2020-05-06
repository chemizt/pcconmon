#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>

#include "coreProviderClasses.hpp"
#include "hardwareDataClasses.hpp"
#include "hardwareProviderClasses.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    DiskDriveProvider* dprov = new DiskDriveProvider();
    dprov->scanForManagedElements();
    int size = dprov->getAllManagedElements().size();
    return 0;
}
