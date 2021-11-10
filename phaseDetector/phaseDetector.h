// # Copyright (c) 2021, Georgia Institute of Technology
// #
// # SPDX-License-Identifier: Apache-2.0
// #
// # Licensed under the Apache License, Version 2.0 (the "License");
// # you may not use this file except in compliance with the License.
// # You may obtain a copy of the License at
// #
// #     http://www.apache.org/licenses/LICENSE-2.0
// #
// # Unless required by applicable law or agreed to in writing, software
// # distributed under the License is distributed on an "AS IS" BASIS,
// # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// # See the License for the specific language governing permissions and
// # limitations under the License.


// Ryan Thomas Lynch
// Georgia Institute of Technology
// ryan.lynch@gatech.edu
// CRNCH Lab


// Phase detection header file
// Version 1.0

#ifndef SST_PHASEDETECTOR_PHASEDETECTOR_H
#define SST_PHASEDETECTOR_PHASEDETECTOR_H

#include <cstdio>
#include <cinttypes>

#include <deque>
#include <vector>
#include <bitset>

#include <sst/core/component.h>



// using namespace std;


// double threshold = 0.5;
// int interval_len = 10000;
// const int signature_len = 1024;
// const int log2_signature_len = 10; // should be log 2 of the above value
// int drop_bits = 3;


// constexpr int DEBUG = 0;
namespace phaseDetector {



    class PhaseDetector : public SST::Component {
        public:
            // phaseDetector();
            // SSI_ELI_REGISTER_COMPONENT()
    };

        
    const uint64_t signature_len = 1024;
    using bitvec = std::bitset<signature_len>;

    typedef int phase_id_type;

    typedef void (*listener_function)(phase_id_type); //listener functor type that takes in a phase ID and returns nothing

    typedef void (*dram_listener_function)(uint64_t, phase_id_type); //listener functor type that takes in a phase ID and returns nothing

    void read_file(char const log_file[], int is_binary = 1);

    void test_listener(phase_id_type current_phase);
    void dram_phase_trace_listener(phase_id_type new_phase);
    void register_dram_trace_listener(dram_listener_function f);

    //used for reading from memtrace binary output files
    struct Binary_output_struct_type {

        bool is_write;
        uint64_t virtual_address;
        uint64_t size_of_access;
        uint64_t instruction_pointer;

    };

    typedef struct Binary_output_struct_type binary_output_struct_t;



    class phaseDetectorEngine {
        private:
            bitvec current_signature;
            bitvec last_signature;
            std::hash<std::bitset<64>> hash_bitvec;
            uint64_t instruction_count = 0;
            uint64_t stable_count = 0;
            phase_id_type phase = -1;
            std::vector<bitvec> phase_table;
            std::deque<phase_id_type> phase_trace;
            std::vector<listener_function> listeners;
        public:
            const uint64_t stable_min = 5;
            const double threshold = 0.5;
            const uint64_t interval_len = 10000;
            const int log2_signature_len = 10;
            const int drop_bits = 3;
            double difference_measure_of_signatures(const bitvec sig1, const bitvec sig2);
            uint64_t hash_address(const uint64_t address);
            void detect(const uint64_t instruction_pointer);
            void init_phase_detector();
            void cleanup_phase_detector(const std::string log_file_name);
            void register_listeners(const listener_function f);
            void print_log_file(const std::string log_file_name);
    };

}
#endif