#include <core.p4>
#include <bmv2/psa.p4>

struct EMPTY {
}

typedef bit<48> EthernetAddress;
header ethernet_t {
    EthernetAddress dstAddr;
    EthernetAddress srcAddr;
    bit<16>         etherType;
}

struct headers_t {
    ethernet_t ethernet;
}

parser MyIP(packet_in buffer, out headers_t hdr, inout EMPTY b, in psa_ingress_parser_input_metadata_t c, in EMPTY d, in EMPTY e) {
    state start {
        buffer.extract<ethernet_t>(hdr.ethernet);
        transition accept;
    }
}

parser MyEP(packet_in buffer, out EMPTY a, inout EMPTY b, in psa_egress_parser_input_metadata_t c, in EMPTY d, in EMPTY e, in EMPTY f) {
    state start {
        transition accept;
    }
}

control MyIC(inout headers_t hdr, inout EMPTY b, in psa_ingress_input_metadata_t c, inout psa_ingress_output_metadata_t d) {
    @noWarn("unused") @name(".NoAction") action NoAction_1() {
    }
    @name("MyIC.reg") Register<bit<16>, bit<10>>(32w1024) reg_0;
    @name("MyIC.execute_register") action execute_register(@name("idx") bit<10> idx) {
    }
    @name("MyIC.tbl") table tbl_0 {
        key = {
            hdr.ethernet.srcAddr: exact @name("hdr.ethernet.srcAddr");
        }
        actions = {
            NoAction_1();
            execute_register();
        }
        default_action = NoAction_1();
    }
    apply {
        tbl_0.apply();
    }
}

control MyEC(inout EMPTY a, inout EMPTY b, in psa_egress_input_metadata_t c, inout psa_egress_output_metadata_t d) {
    apply {
    }
}

control MyID(packet_out buffer, out EMPTY a, out EMPTY b, out EMPTY c, inout headers_t hdr, in EMPTY e, in psa_ingress_output_metadata_t f) {
    apply {
    }
}

control MyED(packet_out buffer, out EMPTY a, out EMPTY b, inout EMPTY c, in EMPTY d, in psa_egress_output_metadata_t e, in psa_egress_deparser_input_metadata_t f) {
    apply {
    }
}

IngressPipeline<headers_t, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY>(MyIP(), MyIC(), MyID()) ip;
EgressPipeline<EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY>(MyEP(), MyEC(), MyED()) ep;
PSA_Switch<headers_t, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY>(ip, PacketReplicationEngine(), ep, BufferingQueueingEngine()) main;
