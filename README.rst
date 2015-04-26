
========
Topcoder
========

References
===========

問題文
    - http://community.topcoder.com/tc?module=MatchList

解説
    - http://apps.topcoder.com/wiki/display/tc/Algorithm+Problem+Set+Analysis

アルゴリズム解説
    - https://www.topcoder.com/community/data-science/data-science-tutorials/

Purpose
=========

- C++で記述する
- 時間をかけてでもきちんと理解する
- 2週目はJavaなど別の言語を使って解く

問題の理解度
============
- 問題文を理解した
- 問題の解き方を理解した
- ソースコードを理解した
- ソースコードを参考に自力で記述
- スクラッチで記述
- 毎回解くことができる

Use util.py
------------

Export::

    export PYTHONPATH=".."

Run::

    cd srmXXX
    python xxx.py

Run it
-------

::

    $ pwd
    /path/to/topcoder
    $ clang++ -I. srmXXX/DivXXXX.cpp & ./a.out

解いたけれども、よくわかってない問題
====================================

**プログラミングで分からないなら小さなサンプルコードを書く、
数学で分からないなら具体的な例を考える**

srm634
-------
- Div2Hard
    - greedyだけれども、解を狭める方法が全くわからなかった

srm633
------
- Div2Easy
    - 再帰を使って記述する

- Div1Easy
    - x - x % s == s * (x // s) の証明
    - vectorの和 (pythonの [1,2,3] + [4,5] = [1,2,3,4,5])

srm629
------
- Div2Medium

    - f(x) = sum{1, n}(|xsi - ti|)
      min f(x) を求める

srm621
------
- Div2Hard

    - XORと線形性の証明
    - XORを使って掃き出し法は使えるのか？

- Div1Easy

    - おそらく32bitなので、小数点以下の計算があわない



Technique
=========

bool型は使いにくい。
1 = true, 0 = falseとしておく。
特にvector<int> でtrueの数を数えるのであれば、その総和とすぐに求められる
