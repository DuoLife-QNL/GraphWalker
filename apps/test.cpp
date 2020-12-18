//
// Created by Ethan on 2020/12/18.
//

#include <string>
#include <fstream>
#include <cmath>
#include <fstream>

#include "api/graphwalker_basic_includes.hpp"
#include "walks/randomwalkwithjump.hpp"
#include "util/toplist.hpp"
#include "util/comperror.hpp"

int main(){
    metrics m("test");
    omp_set_num_threads(10);
#pragma omp parallel for schedule(static)
    for (int i = 0; i < 40; i++){
        m.start_time("testStopFirst");
        sleep(1);
        m.stop_time("testStopFirst");
    }

//    m.start_time("a");
//    sleep(1);
//    m.start_time("a");
//    m.stop_time("a");
//    sleep(1);
//    m.stop_time("a");

    metrics_report(m);
    return 0;
}