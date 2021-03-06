// Generated from Cirq v0.10.0

OPENQASM 2.0;
include "qelib1.inc";


// Qubits: [0, 1, 2, 3, 4, 5]
qreg q[6];
creg m_m[6];


h q[0];
h q[1];
h q[2];
h q[3];
h q[4];
h q[5];

// Gate: ZZ**0.07325447419895686
rz(pi*0.0732544742) q[0];
rz(pi*0.0732544742) q[1];
u3(pi*0.5,0,pi*1.25) q[0];
u3(pi*0.5,0,pi*1.75) q[1];
rx(pi*0.5) q[0];
cx q[0],q[1];
rx(pi*0.4267455258) q[0];
ry(pi*0.5) q[1];
cx q[1],q[0];
rx(pi*0.5) q[1];
rz(pi*0.5) q[1];
cx q[0],q[1];
u3(pi*0.5,pi*1.8232544742,pi*1.0) q[0];
u3(pi*0.5,pi*1.3232544742,pi*1.0) q[1];

// Gate: ZZ**0.07325447419895686
rz(pi*0.0732544742) q[0];
rz(pi*0.0732544742) q[4];
u3(pi*0.5,0,pi*1.25) q[0];
u3(pi*0.5,0,pi*1.75) q[4];
rx(pi*0.5) q[0];
cx q[0],q[4];
rx(pi*0.4267455258) q[0];
ry(pi*0.5) q[4];
cx q[4],q[0];
rx(pi*0.5) q[4];
rz(pi*0.5) q[4];
cx q[0],q[4];
u3(pi*0.5,pi*1.8232544742,pi*1.0) q[0];
u3(pi*0.5,pi*1.3232544742,pi*1.0) q[4];

// Gate: ZZ**0.07325447419895686
rz(pi*0.0732544742) q[1];
rz(pi*0.0732544742) q[5];
u3(pi*0.5,0,pi*1.25) q[1];
u3(pi*0.5,0,pi*1.75) q[5];
rx(pi*0.5) q[1];
cx q[1],q[5];
rx(pi*0.4267455258) q[1];
ry(pi*0.5) q[5];
cx q[5],q[1];
rx(pi*0.5) q[5];
rz(pi*0.5) q[5];
cx q[1],q[5];
u3(pi*0.5,pi*1.8232544742,pi*1.0) q[1];
u3(pi*0.5,pi*1.3232544742,pi*1.0) q[5];

// Gate: ZZ**0.07325447419895686
rz(pi*0.0732544742) q[0];
rz(pi*0.0732544742) q[2];
u3(pi*0.5,0,pi*1.25) q[0];
u3(pi*0.5,0,pi*1.75) q[2];
rx(pi*0.5) q[0];
cx q[0],q[2];
rx(pi*0.4267455258) q[0];
ry(pi*0.5) q[2];
cx q[2],q[0];
rx(pi*0.5) q[2];
rz(pi*0.5) q[2];
cx q[0],q[2];
u3(pi*0.5,pi*1.8232544742,pi*1.0) q[0];
u3(pi*0.5,pi*1.3232544742,pi*1.0) q[2];

// Gate: ZZ**0.07325447419895686
rz(pi*0.0732544742) q[1];
rz(pi*0.0732544742) q[3];
u3(pi*0.5,0,pi*1.25) q[1];
u3(pi*0.5,0,pi*1.75) q[3];
rx(pi*0.5) q[1];
cx q[1],q[3];
rx(pi*0.4267455258) q[1];
ry(pi*0.5) q[3];
cx q[3],q[1];
rx(pi*0.5) q[3];
rz(pi*0.5) q[3];
cx q[1],q[3];
u3(pi*0.5,pi*1.8232544742,pi*1.0) q[1];
u3(pi*0.5,pi*1.3232544742,pi*1.0) q[3];

// Gate: ZZ**0.07325447419895686
rz(pi*0.0732544742) q[2];
rz(pi*0.0732544742) q[4];
u3(pi*0.5,0,pi*1.25) q[2];
u3(pi*0.5,0,pi*1.75) q[4];
rx(pi*0.5) q[2];
cx q[2],q[4];
rx(pi*0.4267455258) q[2];
ry(pi*0.5) q[4];
cx q[4],q[2];
rx(pi*0.5) q[4];
rz(pi*0.5) q[4];
cx q[2],q[4];
u3(pi*0.5,pi*1.8232544742,pi*1.0) q[2];
u3(pi*0.5,pi*1.3232544742,pi*1.0) q[4];

rx(pi*1.7969807537) q[0];
rx(pi*1.7969807537) q[1];

// Gate: ZZ**0.07325447419895686
rz(pi*0.0732544742) q[2];
rz(pi*0.0732544742) q[3];
u3(pi*0.5,0,pi*1.25) q[2];
u3(pi*0.5,0,pi*1.75) q[3];
rx(pi*0.5) q[2];
cx q[2],q[3];
rx(pi*0.4267455258) q[2];
ry(pi*0.5) q[3];
cx q[3],q[2];
rx(pi*0.5) q[3];
rz(pi*0.5) q[3];
cx q[2],q[3];
u3(pi*0.5,pi*1.8232544742,pi*1.0) q[2];
u3(pi*0.5,pi*1.3232544742,pi*1.0) q[3];

// Gate: ZZ**0.07325447419895686
rz(pi*0.0732544742) q[4];
rz(pi*0.0732544742) q[5];
u3(pi*0.5,0,pi*1.25) q[4];
u3(pi*0.5,0,pi*1.75) q[5];
rx(pi*0.5) q[4];
cx q[4],q[5];
rx(pi*0.4267455258) q[4];
ry(pi*0.5) q[5];
cx q[5],q[4];
rx(pi*0.5) q[5];
rz(pi*0.5) q[5];
cx q[4],q[5];
u3(pi*0.5,pi*1.8232544742,pi*1.0) q[4];
u3(pi*0.5,pi*1.3232544742,pi*1.0) q[5];

// Gate: ZZ**0.4786584972070304
rz(pi*0.4786584972) q[0];
rz(pi*0.4786584972) q[1];
u3(pi*0.5,0,pi*0.75) q[0];
u3(pi*0.5,0,pi*0.75) q[1];
rx(pi*0.5) q[0];
cx q[0],q[1];
rx(pi*0.0213415028) q[0];
ry(pi*0.5) q[1];
cx q[1],q[0];
rx(pi*0.5) q[1];
rz(pi*0.5) q[1];
cx q[0],q[1];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[0];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[1];

// Gate: ZZ**0.07325447419895686
rz(pi*0.0732544742) q[5];
rz(pi*0.0732544742) q[3];
u3(pi*0.5,0,pi*1.25) q[5];
u3(pi*0.5,0,pi*1.75) q[3];
rx(pi*0.5) q[5];
cx q[5],q[3];
rx(pi*0.4267455258) q[5];
ry(pi*0.5) q[3];
cx q[3],q[5];
rx(pi*0.5) q[3];
rz(pi*0.5) q[3];
cx q[5],q[3];
u3(pi*0.5,pi*1.8232544742,pi*1.0) q[5];
u3(pi*0.5,pi*1.3232544742,pi*1.0) q[3];

rx(pi*1.7969807537) q[2];
rx(pi*1.7969807537) q[4];
rx(pi*1.7969807537) q[3];
rx(pi*1.7969807537) q[5];

// Gate: ZZ**0.4786584972070304
rz(pi*0.4786584972) q[0];
rz(pi*0.4786584972) q[4];
u3(pi*0.5,0,pi*0.75) q[0];
u3(pi*0.5,0,pi*0.75) q[4];
rx(pi*0.5) q[0];
cx q[0],q[4];
rx(pi*0.0213415028) q[0];
ry(pi*0.5) q[4];
cx q[4],q[0];
rx(pi*0.5) q[4];
rz(pi*0.5) q[4];
cx q[0],q[4];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[0];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[4];

// Gate: ZZ**0.4786584972070304
rz(pi*0.4786584972) q[0];
rz(pi*0.4786584972) q[2];
u3(pi*0.5,0,pi*0.75) q[0];
u3(pi*0.5,0,pi*0.75) q[2];
rx(pi*0.5) q[0];
cx q[0],q[2];
rx(pi*0.0213415028) q[0];
ry(pi*0.5) q[2];
cx q[2],q[0];
rx(pi*0.5) q[2];
rz(pi*0.5) q[2];
cx q[0],q[2];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[0];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[2];

// Gate: ZZ**0.4786584972070304
rz(pi*0.4786584972) q[1];
rz(pi*0.4786584972) q[5];
u3(pi*0.5,0,pi*0.75) q[1];
u3(pi*0.5,0,pi*0.75) q[5];
rx(pi*0.5) q[1];
cx q[1],q[5];
rx(pi*0.0213415028) q[1];
ry(pi*0.5) q[5];
cx q[5],q[1];
rx(pi*0.5) q[5];
rz(pi*0.5) q[5];
cx q[1],q[5];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[1];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[5];

// Gate: ZZ**0.4786584972070304
rz(pi*0.4786584972) q[1];
rz(pi*0.4786584972) q[3];
u3(pi*0.5,0,pi*0.75) q[1];
u3(pi*0.5,0,pi*0.75) q[3];
rx(pi*0.5) q[1];
cx q[1],q[3];
rx(pi*0.0213415028) q[1];
ry(pi*0.5) q[3];
cx q[3],q[1];
rx(pi*0.5) q[3];
rz(pi*0.5) q[3];
cx q[1],q[3];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[1];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[3];

// Gate: ZZ**0.4786584972070304
rz(pi*0.4786584972) q[2];
rz(pi*0.4786584972) q[4];
u3(pi*0.5,0,pi*0.75) q[2];
u3(pi*0.5,0,pi*0.75) q[4];
rx(pi*0.5) q[2];
cx q[2],q[4];
rx(pi*0.0213415028) q[2];
ry(pi*0.5) q[4];
cx q[4],q[2];
rx(pi*0.5) q[4];
rz(pi*0.5) q[4];
cx q[2],q[4];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[2];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[4];

rx(pi*0.6966036075) q[0];

// Gate: ZZ**0.4786584972070304
rz(pi*0.4786584972) q[2];
rz(pi*0.4786584972) q[3];
u3(pi*0.5,0,pi*0.75) q[2];
u3(pi*0.5,0,pi*0.75) q[3];
rx(pi*0.5) q[2];
cx q[2],q[3];
rx(pi*0.0213415028) q[2];
ry(pi*0.5) q[3];
cx q[3],q[2];
rx(pi*0.5) q[3];
rz(pi*0.5) q[3];
cx q[2],q[3];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[2];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[3];

// Gate: ZZ**0.4786584972070304
rz(pi*0.4786584972) q[4];
rz(pi*0.4786584972) q[5];
u3(pi*0.5,0,pi*0.75) q[4];
u3(pi*0.5,0,pi*0.75) q[5];
rx(pi*0.5) q[4];
cx q[4],q[5];
rx(pi*0.0213415028) q[4];
ry(pi*0.5) q[5];
cx q[5],q[4];
rx(pi*0.5) q[5];
rz(pi*0.5) q[5];
cx q[4],q[5];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[4];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[5];

rx(pi*0.6966036075) q[1];

// Gate: ZZ**0.4786584972070304
rz(pi*0.4786584972) q[5];
rz(pi*0.4786584972) q[3];
u3(pi*0.5,0,pi*0.75) q[5];
u3(pi*0.5,0,pi*0.75) q[3];
rx(pi*0.5) q[5];
cx q[5],q[3];
rx(pi*0.0213415028) q[5];
ry(pi*0.5) q[3];
cx q[3],q[5];
rx(pi*0.5) q[3];
rz(pi*0.5) q[3];
cx q[5],q[3];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[5];
u3(pi*0.5,pi*0.7286584972,pi*1.0) q[3];

rx(pi*0.6966036075) q[2];
rx(pi*0.6966036075) q[4];
rx(pi*0.6966036075) q[3];
rx(pi*0.6966036075) q[5];

// Gate: cirq.MeasurementGate(6, 'm', ())
measure q[0] -> m_m[0];
measure q[1] -> m_m[1];
measure q[2] -> m_m[2];
measure q[3] -> m_m[3];
measure q[4] -> m_m[4];
measure q[5] -> m_m[5];
