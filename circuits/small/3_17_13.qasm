OPENQASM 2.0;
include "qelib1.inc";
qreg q[15];
creg c[15];
h q[7];
cx q[0], q[14];
cx q[0], q[4];
cx q[14], q[3];
cx q[4], q[3];



