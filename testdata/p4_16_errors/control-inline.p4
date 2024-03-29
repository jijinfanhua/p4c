/*
Copyright 2016-present Barefoot Networks, Inc. 

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
// p4lang/p4c#115
#include<core.p4>
#include<v1model.p4>

typedef standard_metadata_t std_m;
struct H { };
struct M { };

parser ParserI(packet_in pk, out H hdr, inout M meta, inout std_m smeta) {
    state start { transition accept; }
}

control VC(in H hdr, inout M meta) {
    apply { }
}

control Main(inout H hdr, inout M meta, inout std_m smeta) {
    apply { 
        VC() vc;  // illegal instance within an apply block
        vc.apply(hdr, meta);
    }
}

control CC(inout H hdr, inout M meta) {
    apply { }
}

control DeparserI(packet_out b, in H hdr) {
    apply { }
}

V1Switch(ParserI(), VC(), Main(), Main(), CC(), DeparserI()) main;
