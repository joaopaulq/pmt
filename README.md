# pmt

## usage
```
pmt [OPTIONS] foo.txt pat [pat]*
```

## options
|  algorithm | option | pattern | match    | paper |
|------------|--------|---------|----------|-------|
| knuth-morris-pratt | `-k` | single | exact | [Fast Pattern Matching in Strings](https://www.cin.ufpe.br/~paguso/courses/if767/bib/KMP_1977.pdf) |
| boyer-moore | `-b` | single | exact | [A Fast String Searching Algorithm](https://www.cin.ufpe.br/~paguso/courses/if767/bib/Boyer_1977.pdf) |
| sellers | `-s E_MAX` | single | approximate | [The Theory and Computation of Evolutionary Distances: Pattern Recognition](https://www.cin.ufpe.br/~paguso/courses/if767/bib/Sellers_1980.pdf) |
| aho-corasick| `-a` | multiple | exact | [Efficient String Matching: An Aid to Bibliographic Search ](https://www.cin.ufpe.br/~paguso/courses/if767/bib/Aho_1975.pdf)
