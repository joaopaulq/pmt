# pmt
A command-line interface for pattern matching.

## Usage
```
pmt [OPTIONS] file.txt pat [pat...]
```

## Options
|  Algorithm | Option | Pattern | Match    | Paper |
|------------|--------|---------|----------|-------|
| Knuth-Morris-Pratt | `-k` | Single | Exact | [Fast Pattern Matching in Strings](https://www.cin.ufpe.br/~paguso/courses/if767/bib/KMP_1977.pdf) |
| Boyer-Moore | `-b` | Single | Exact | [A Fast String Searching Algorithm](https://www.cin.ufpe.br/~paguso/courses/if767/bib/Boyer_1977.pdf) |
| Sellers | `-s E_MAX` | Single | Approximate | [The Theory and Computation of Evolutionary Distances: Pattern Recognition](https://www.cin.ufpe.br/~paguso/courses/if767/bib/Sellers_1980.pdf) |
| Aho-Corasick| `-a` | Multiple | Exact | [Efficient String Matching: An Aid to Bibliographic Search ](https://www.cin.ufpe.br/~paguso/courses/if767/bib/Aho_1975.pdf)
