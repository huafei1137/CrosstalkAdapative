OPENQASM 2.0;
include "qelib1.inc";
qreg q[10];
creg m_m[10];
h q[0];
rz(2.327699) q[0];
u3(pi/2,pi,4.0746555) q[0];
rx(pi/2) q[0];
h q[1];
rz(2.327699) q[1];
u3(pi/2,0,0.93306288) q[1];
cx q[0],q[1];
rx(0.75690271) q[0];
ry(pi/2) q[1];
cx q[1],q[0];
rx(pi/2) q[1];
rz(pi/2) q[1];
cx q[0],q[1];
u3(pi/2,4.5362288,0) q[0];
rz(2.327699) q[0];
u3(pi/2,pi,4.0746555) q[0];
rx(pi/2) q[0];
u3(pi/2,1.3946362,pi) q[1];
rz(2.327699) q[1];
u3(pi/2,pi,4.0746555) q[1];
rx(pi/2) q[1];
h q[2];
rz(2.327699) q[2];
u3(pi/2,pi,4.0746555) q[2];
rx(pi/2) q[2];
h q[3];
rz(2.327699) q[3];
u3(pi/2,0,0.93306288) q[3];
h q[4];
rz(2.327699) q[4];
u3(pi/2,0,0.93306288) q[4];
cx q[0],q[4];
rx(0.75690271) q[0];
ry(pi/2) q[4];
cx q[4],q[0];
rx(pi/2) q[4];
rz(pi/2) q[4];
cx q[0],q[4];
u3(pi/2,4.5362288,0) q[0];
rz(2.327699) q[0];
u3(pi/2,pi,4.0746555) q[0];
rx(pi/2) q[0];
u3(pi/2,1.3946362,pi) q[4];
rz(2.327699) q[4];
u3(pi/2,pi,4.0746555) q[4];
rx(pi/2) q[4];
cx q[4],q[3];
ry(pi/2) q[3];
rx(0.75690271) q[4];
cx q[3],q[4];
rx(pi/2) q[3];
rz(pi/2) q[3];
cx q[4],q[3];
u3(pi/2,1.3946362,pi) q[3];
rz(2.327699) q[3];
u3(pi/2,pi,4.0746555) q[3];
rx(pi/2) q[3];
u3(pi/2,4.5362288,0) q[4];
rz(2.327699) q[4];
u3(pi/2,pi,4.0746555) q[4];
rx(pi/2) q[4];
h q[5];
rz(2.327699) q[5];
u3(pi/2,0,0.93306288) q[5];
cx q[0],q[5];
rx(0.75690271) q[0];
ry(pi/2) q[5];
cx q[5],q[0];
rx(pi/2) q[5];
rz(pi/2) q[5];
cx q[0],q[5];
u3(pi/2,4.5362288,0) q[0];
rx(5.7739128) q[0];
rz(3.0633773) q[0];
u3(pi/2,0,3*pi/4) q[0];
rx(pi/2) q[0];
u3(pi/2,1.3946362,pi) q[5];
rz(2.327699) q[5];
u3(pi/2,0,0.93306288) q[5];
cx q[4],q[5];
rx(0.75690271) q[4];
ry(pi/2) q[5];
cx q[5],q[4];
rx(pi/2) q[5];
rz(pi/2) q[5];
cx q[4],q[5];
u3(pi/2,4.5362288,0) q[4];
rx(5.7739128) q[4];
rz(3.0633773) q[4];
u3(pi/2,pi,5*pi/4) q[4];
u3(pi/2,1.3946362,pi) q[5];
rz(2.327699) q[5];
u3(pi/2,0,0.93306288) q[5];
h q[6];
rz(2.327699) q[6];
u3(pi/2,0,0.93306288) q[6];
h q[7];
rz(2.327699) q[7];
u3(pi/2,0,0.93306288) q[7];
cx q[3],q[7];
rx(0.75690271) q[3];
ry(pi/2) q[7];
cx q[7],q[3];
rx(pi/2) q[7];
rz(pi/2) q[7];
cx q[3],q[7];
u3(pi/2,4.5362288,0) q[3];
rz(2.327699) q[3];
u3(pi/2,pi,4.0746555) q[3];
rx(pi/2) q[3];
cx q[3],q[6];
rx(0.75690271) q[3];
ry(pi/2) q[6];
cx q[6],q[3];
rx(pi/2) q[6];
rz(pi/2) q[6];
cx q[3],q[6];
u3(pi/2,4.5362288,0) q[3];
rx(5.7739128) q[3];
rz(3.0633773) q[3];
u3(pi/2,pi,5*pi/4) q[3];
u3(pi/2,1.3946362,pi) q[6];
rz(2.327699) q[6];
u3(pi/2,pi,4.0746555) q[6];
rx(pi/2) q[6];
u3(pi/2,1.3946362,pi) q[7];
rz(2.327699) q[7];
u3(pi/2,0,0.93306288) q[7];
cx q[2],q[7];
rx(0.75690271) q[2];
ry(pi/2) q[7];
cx q[7],q[2];
rx(pi/2) q[7];
rz(pi/2) q[7];
cx q[2],q[7];
u3(pi/2,4.5362288,0) q[2];
rz(2.327699) q[2];
u3(pi/2,pi,4.0746555) q[2];
rx(pi/2) q[2];
u3(pi/2,1.3946362,pi) q[7];
rz(2.327699) q[7];
u3(pi/2,pi,4.0746555) q[7];
rx(pi/2) q[7];
cx q[7],q[5];
ry(pi/2) q[5];
rx(0.75690271) q[7];
cx q[5],q[7];
rx(pi/2) q[5];
rz(pi/2) q[5];
cx q[7],q[5];
u3(pi/2,1.3946362,pi) q[5];
rx(5.7739128) q[5];
rz(3.0633773) q[5];
u3(pi/2,pi,5*pi/4) q[5];
u3(pi/2,4.5362288,0) q[7];
rx(5.7739128) q[7];
rz(3.0633773) q[7];
u3(pi/2,pi,5*pi/4) q[7];
h q[8];
rz(2.327699) q[8];
u3(pi/2,0,0.93306288) q[8];
cx q[1],q[8];
rx(0.75690271) q[1];
ry(pi/2) q[8];
cx q[8],q[1];
rx(pi/2) q[8];
rz(pi/2) q[8];
cx q[1],q[8];
u3(pi/2,4.5362288,0) q[1];
rz(2.327699) q[1];
u3(pi/2,pi,4.0746555) q[1];
rx(pi/2) q[1];
u3(pi/2,1.3946362,pi) q[8];
rz(2.327699) q[8];
u3(pi/2,0,0.93306288) q[8];
h q[9];
rz(2.327699) q[9];
u3(pi/2,0,0.93306288) q[9];
cx q[1],q[9];
rx(0.75690271) q[1];
ry(pi/2) q[9];
cx q[9],q[1];
rx(pi/2) q[9];
rz(pi/2) q[9];
cx q[1],q[9];
u3(pi/2,4.5362288,0) q[1];
rx(5.7739128) q[1];
rz(3.0633773) q[1];
u3(pi/2,pi,5*pi/4) q[1];
cx q[0],q[1];
rx(1.4925809) q[0];
ry(pi/2) q[1];
cx q[1],q[0];
rx(pi/2) q[1];
rz(pi/2) q[1];
cx q[0],q[1];
u3(pi/2,0.70718276,pi) q[0];
rz(3.0633773) q[0];
u3(pi/2,0,3*pi/4) q[0];
rx(pi/2) q[0];
cx q[0],q[4];
rx(1.4925809) q[0];
u3(pi/2,5.4195717,0) q[1];
rz(3.0633773) q[1];
u3(pi/2,0,3*pi/4) q[1];
rx(pi/2) q[1];
ry(pi/2) q[4];
cx q[4],q[0];
rx(pi/2) q[4];
rz(pi/2) q[4];
cx q[0],q[4];
u3(pi/2,0.70718276,pi) q[0];
rz(3.0633773) q[0];
u3(pi/2,0,3*pi/4) q[0];
rx(pi/2) q[0];
cx q[0],q[5];
rx(1.4925809) q[0];
u3(pi/2,5.4195717,0) q[4];
rz(3.0633773) q[4];
u3(pi/2,0,3*pi/4) q[4];
rx(pi/2) q[4];
cx q[4],q[3];
ry(pi/2) q[3];
rx(1.4925809) q[4];
cx q[3],q[4];
rx(pi/2) q[3];
rz(pi/2) q[3];
cx q[4],q[3];
u3(pi/2,5.4195717,0) q[3];
rz(3.0633773) q[3];
u3(pi/2,0,3*pi/4) q[3];
rx(pi/2) q[3];
cx q[3],q[7];
rx(1.4925809) q[3];
u3(pi/2,0.70718276,pi) q[4];
rz(3.0633773) q[4];
u3(pi/2,0,3*pi/4) q[4];
rx(pi/2) q[4];
ry(pi/2) q[5];
cx q[5],q[0];
rx(pi/2) q[5];
rz(pi/2) q[5];
cx q[0],q[5];
u3(pi/2,0.70718276,pi) q[0];
rx(1.4336166) q[0];
u3(pi/2,5.4195717,0) q[5];
rz(3.0633773) q[5];
u3(pi/2,pi,5*pi/4) q[5];
cx q[4],q[5];
rx(1.4925809) q[4];
ry(pi/2) q[5];
cx q[5],q[4];
rx(pi/2) q[5];
rz(pi/2) q[5];
cx q[4],q[5];
u3(pi/2,0.70718276,pi) q[4];
rx(1.4336166) q[4];
u3(pi/2,5.4195717,0) q[5];
rz(3.0633773) q[5];
u3(pi/2,pi,5*pi/4) q[5];
ry(pi/2) q[7];
cx q[7],q[3];
rx(pi/2) q[7];
rz(pi/2) q[7];
cx q[3],q[7];
u3(pi/2,0.70718276,pi) q[3];
rz(3.0633773) q[3];
u3(pi/2,0,3*pi/4) q[3];
rx(pi/2) q[3];
u3(pi/2,5.4195717,0) q[7];
rz(3.0633773) q[7];
u3(pi/2,pi,5*pi/4) q[7];
u3(pi/2,1.3946362,pi) q[9];
rz(2.327699) q[9];
u3(pi/2,0,0.93306288) q[9];
cx q[2],q[9];
rx(0.75690271) q[2];
ry(pi/2) q[9];
cx q[9],q[2];
rx(pi/2) q[9];
rz(pi/2) q[9];
cx q[2],q[9];
u3(pi/2,4.5362288,0) q[2];
rz(2.327699) q[2];
u3(pi/2,pi,4.0746555) q[2];
rx(pi/2) q[2];
cx q[2],q[8];
rx(0.75690271) q[2];
ry(pi/2) q[8];
cx q[8],q[2];
rx(pi/2) q[8];
rz(pi/2) q[8];
cx q[2],q[8];
u3(pi/2,4.5362288,0) q[2];
rx(5.7739128) q[2];
rz(3.0633773) q[2];
u3(pi/2,0,3*pi/4) q[2];
rx(pi/2) q[2];
cx q[2],q[7];
rx(1.4925809) q[2];
ry(pi/2) q[7];
cx q[7],q[2];
rx(pi/2) q[7];
rz(pi/2) q[7];
cx q[2],q[7];
u3(pi/2,0.70718276,pi) q[2];
rz(3.0633773) q[2];
u3(pi/2,0,3*pi/4) q[2];
rx(pi/2) q[2];
u3(pi/2,5.4195717,0) q[7];
rz(3.0633773) q[7];
u3(pi/2,0,3*pi/4) q[7];
rx(pi/2) q[7];
cx q[7],q[5];
ry(pi/2) q[5];
rx(1.4925809) q[7];
cx q[5],q[7];
rx(pi/2) q[5];
rz(pi/2) q[5];
cx q[7],q[5];
u3(pi/2,5.4195717,0) q[5];
rx(1.4336166) q[5];
u3(pi/2,0.70718276,pi) q[7];
rx(1.4336166) q[7];
u3(pi/2,1.3946362,pi) q[8];
rz(2.327699) q[8];
u3(pi/2,0,0.93306288) q[8];
cx q[6],q[8];
rx(0.75690271) q[6];
ry(pi/2) q[8];
cx q[8],q[6];
rx(pi/2) q[8];
rz(pi/2) q[8];
cx q[6],q[8];
u3(pi/2,4.5362288,0) q[6];
rz(2.327699) q[6];
u3(pi/2,pi,4.0746555) q[6];
rx(pi/2) q[6];
u3(pi/2,1.3946362,pi) q[8];
rx(5.7739128) q[8];
rz(3.0633773) q[8];
u3(pi/2,pi,5*pi/4) q[8];
cx q[1],q[8];
rx(1.4925809) q[1];
ry(pi/2) q[8];
cx q[8],q[1];
rx(pi/2) q[8];
rz(pi/2) q[8];
cx q[1],q[8];
u3(pi/2,0.70718276,pi) q[1];
rz(3.0633773) q[1];
u3(pi/2,0,3*pi/4) q[1];
rx(pi/2) q[1];
u3(pi/2,5.4195717,0) q[8];
rz(3.0633773) q[8];
u3(pi/2,pi,5*pi/4) q[8];
u3(pi/2,1.3946362,pi) q[9];
rz(2.327699) q[9];
u3(pi/2,0,0.93306288) q[9];
cx q[6],q[9];
rx(0.75690271) q[6];
ry(pi/2) q[9];
cx q[9],q[6];
rx(pi/2) q[9];
rz(pi/2) q[9];
cx q[6],q[9];
u3(pi/2,4.5362288,0) q[6];
rx(5.7739128) q[6];
rz(3.0633773) q[6];
u3(pi/2,pi,5*pi/4) q[6];
cx q[3],q[6];
rx(1.4925809) q[3];
ry(pi/2) q[6];
cx q[6],q[3];
rx(pi/2) q[6];
rz(pi/2) q[6];
cx q[3],q[6];
u3(pi/2,0.70718276,pi) q[3];
rx(1.4336166) q[3];
u3(pi/2,5.4195717,0) q[6];
rz(3.0633773) q[6];
u3(pi/2,0,3*pi/4) q[6];
rx(pi/2) q[6];
u3(pi/2,1.3946362,pi) q[9];
rx(5.7739128) q[9];
rz(3.0633773) q[9];
u3(pi/2,pi,5*pi/4) q[9];
cx q[1],q[9];
rx(1.4925809) q[1];
ry(pi/2) q[9];
cx q[9],q[1];
rx(pi/2) q[9];
rz(pi/2) q[9];
cx q[1],q[9];
u3(pi/2,0.70718276,pi) q[1];
rx(1.4336166) q[1];
u3(pi/2,5.4195717,0) q[9];
rz(3.0633773) q[9];
u3(pi/2,pi,5*pi/4) q[9];
cx q[2],q[9];
rx(1.4925809) q[2];
ry(pi/2) q[9];
cx q[9],q[2];
rx(pi/2) q[9];
rz(pi/2) q[9];
cx q[2],q[9];
u3(pi/2,0.70718276,pi) q[2];
rz(3.0633773) q[2];
u3(pi/2,0,3*pi/4) q[2];
rx(pi/2) q[2];
cx q[2],q[8];
rx(1.4925809) q[2];
ry(pi/2) q[8];
cx q[8],q[2];
rx(pi/2) q[8];
rz(pi/2) q[8];
cx q[2],q[8];
u3(pi/2,0.70718276,pi) q[2];
rx(1.4336166) q[2];
u3(pi/2,5.4195717,0) q[8];
rz(3.0633773) q[8];
u3(pi/2,pi,5*pi/4) q[8];
cx q[6],q[8];
rx(1.4925809) q[6];
ry(pi/2) q[8];
cx q[8],q[6];
rx(pi/2) q[8];
rz(pi/2) q[8];
cx q[6],q[8];
u3(pi/2,0.70718276,pi) q[6];
rz(3.0633773) q[6];
u3(pi/2,0,3*pi/4) q[6];
rx(pi/2) q[6];
u3(pi/2,5.4195717,0) q[8];
rx(1.4336166) q[8];
u3(pi/2,5.4195717,0) q[9];
rz(3.0633773) q[9];
u3(pi/2,pi,5*pi/4) q[9];
cx q[6],q[9];
rx(1.4925809) q[6];
ry(pi/2) q[9];
cx q[9],q[6];
rx(pi/2) q[9];
rz(pi/2) q[9];
cx q[6],q[9];
u3(pi/2,0.70718276,pi) q[6];
rx(1.4336166) q[6];
u3(pi/2,5.4195717,0) q[9];
rx(1.4336166) q[9];
