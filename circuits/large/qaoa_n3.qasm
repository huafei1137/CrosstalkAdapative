OPENQASM 2.0;
include "qelib1.inc";


qreg q[3];


h q[0];
h q[1];
h q[2];
cx q[0],q[2];
rz(pi*1.79986) q[2];
cx q[0],q[2];
cx q[0],q[1];
cx q[1],q[2];
rz(pi*3.59973) q[2];
cx q[1],q[2];
cx q[0],q[1];
rx(pi*0.545344) q[2];
rz(pi*5.39959) q[1];
rx(pi*0.545344) q[0];
rx(pi*0.545344) q[1];

