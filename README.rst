
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

