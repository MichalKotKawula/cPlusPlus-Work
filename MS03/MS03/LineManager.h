
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include<iostream>
#include<vector>
#include<deque>
#include <string>
#include "Workstation.h"

namespace sdds {
    class LineManager {

        std::vector<Workstation*> activeLine{};
        size_t m_cntCustomerOrder{ 0u };
        Workstation* m_firstStation{ nullptr };

    public:

        LineManager() {};

        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        
        void linkStations();
        
        bool run(std::ostream& os);
        
        void display(std::ostream& os) const;
    };
}

#endif