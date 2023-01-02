# Page-Rank
Simplified Google Page Rank Algorithm
> The PageRank algorithm is an algorithm used by Google Search to rank web pages in their search engine results to order or rank different web pages on the internet.

## Web Representation
The entire internet consists of different web pages that can be represented as a graph. Each node represents a webpage, and each edge represents a link between two web pages. I implemented an Adjacency List graph in this project because it has better space complexity.

## User Input
Line 1 contains the number of lines (n) that will follow and the number of power iterations (p) to perform. Each line from 2 to n+1 will contain two URL’s – from_page to_page separated by a single space. This means that the from_page points to the URL to_page.

### Example
> 7 2 \
> google.com gmail.com \
> google.com maps.com \
> facebook.com ufl.edu \
> ufl.edu google.com \
> ufl.edu gmail.com \
> maps.com facebook.com \
> gmail.com maps.com

## Output Result
Result PageRank of all pages after p powerIterations in ascending alphabetical order of webpage. Also, I round off the page's rank to two decimal places.

### Example
> facebook.com 0.20 \
> gmail.com 0.20 \
> google.com 0.10 \
> maps.com 0.30 \
> ufl.edu 0.20
