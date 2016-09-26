# hyphahandlers

Handlers for the hypha framework.

## Installation

```{r, engine='bash', count_lines}
git clone https://gitlab.chriamue.de/hypha/hypha.git
cd hypha
mkdir build
cd build
cmake ..
make
cd ../..

git clone https://gitlab.chriamue.de/hypha/hyphahandlers.git
cd hyphahandlers
mkdir build
cd build
cmake -Dhypha_DIR=../../hypha ..
make
```
