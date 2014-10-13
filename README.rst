
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

srm633
------
- Div2Easy
    - 再帰を使って記述する

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
