#!/usr/bin/env python
#coding:utf-8
#
#   solution 1, 子问题:
#   用V[W]表示"负重为W的背包在不超过负重的情况下，可以获取的最大价值"
#
#       V[W] = max{ V[W - w[i]] + v[i] }, i = 1,...,n
#   解题方法同找零钱
#   
#   solution 2, 子问题:
#   用V[i, W]表示"前i个物品，放入负重为W背包中，可以获取的最大价值"
#   
#       V[i, W] = 
