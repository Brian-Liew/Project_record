# 粒子群算法（PSO）数学原理

一种启发式的优化方法，具体的例子就是：在一片区域内只有一块食物（极值），所有的鸟都不知道食物在哪里（初始化的粒子），但是它们能够感受到当前的位置距离食物多远（根据当前的最优值进行优化）。数学化的算法原理：初始化一组随机粒子，每一次迭代的粒子通过跟踪两个极值进行更新自己，这两个极值是关键，一个是根据自身找到的最优解，另一个是整个种群目前找到的最优值。

下面展开具体分析：

假设在第一个D维目标搜索空间中（D元函数），有N个粒子组成一个群落，其中第i个粒子是一个N维向量：
$$
X_i=(x_{i1},x_{i2},x_{i3},...x_{iD}),i=1,2,3...,N
$$
每一个粒子都有自己的速度，也是一个N维向量：
$$
V_i=(v_{i1},v_{i2},v_{i3},...v_{iD}),i=1,2,3...,N
$$
对于每一个粒子自身而言的那个极值，就是迄今为止搜索到的最优位置为个体极值，记为：
$$
P_{best}=(P_{i1},P_{i2},...,P_{iD}),i=1,2,...,N
$$
而对于全局而言，整个粒子群迄今为止搜索到的最优位置为全局极值，记为：
$$
g_{best}=(P_{g1},P_{g2}...P_{gN})
$$
找到这两个最优值之后就是更新自己的速度和位置：
$$
v_{id}=w\times v_{id}+c_1r_1(P_{id}-x_{id})+c_2r_2(P_{gd}-x_{id})
$$
其中c1和c2是学习因子，也就是加速常数，r1和r2是随机数，这个式子的第一部分是惯性，表示粒子原本1维持的速度，第二部分是认知部分，反映历史经验的记忆，第三部分是社会部分，反映粒子之间的合作经验。

下面对一个函数进行优化，作为一个应用实例：

需要优化的目标函数是：
$$
target=x^2+y^2+z^2
$$

```python
#define the optimal function 
#feed the array return the result
def target(nparray):
	return nparray[0]**2 + nparray[1]**2 + nparray[2]**2

N = 30 #amount of the partical
D = 3 #dimension of the result function
M = 1000 #iterations
c1 = 0.5
c2 = 0.5 #acceleration constant
w = 0.6 #inertia factor

import random
import numpy as np

X=np.zeros((N,D))
Y=np.zeros((N,D))
V=np.zeros((N,D))

#init the X(pos) and V(velocity)
for i in range(N):
	for j in range(D):
		X[i][j]=random.random()
		V[i][j]=random.random()

#init the optimal pos of each partical
P = np.zeros(N)
for i in range(N):
	P[i]=target(X[i])
	Y[i]=X[i]

#init the optimal pos of the whole partical
pg = X[0]

for i in range(1,N):
	if float(target(X[i]))<float(target(pg)):
		pg=X[i]

# the main loop 
for j in range(M):
	for i in range(N):
		V[i]=w*V[i]+c1*random.random()*(Y[i]-X[i])+c2*random.random()*(pg-X[i])
		X[i]=X[i]+V[i]
		if target(X[i])<P[i]:
			P[i]=target(X[i])
			Y[i]=X[i]
		if P[i]<target(pg):
			pg=Y[i]

print(pg)
print(target(pg))

```

> [-5.58919468e-113 -1.24070745e-113 -7.58949018e-113]
> 9.03788133030397e-225
> [Finished in 2.8s]