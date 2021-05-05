OPENQASM 2.0;
include "qelib1.inc";
qreg q[15];
creg c[15];
cx q[1],q[11];
cx q[2],q[13];
cx q[5],q[6];
cx q[8],q[9];

cx q[1],q[13];
cx q[2],q[11];



