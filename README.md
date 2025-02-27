# Morrígan Project

The Morrígan project is aimed at adding phase detection and model swapping capabilities to the [Structural Simulation Toolkit](https://sst-simulator.org/). 

## Installation
First install Python 3, then follow these instructions.

```
git clone git@github.com:hpcgarage/morrigan.git
cd morrigan
git submodule update --init --recursive
./install-dependencies.sh
./configure-morrigan.sh
./build-and-install-morrigan.sh
source morrigan-env.sh
```

## Troubleshooting
Some simple logs are generated in `logs/`. One file should be generated for each of the three scripts you run during the installation process. 

#### `install-dependencies.out`
This file should have 4 lines of output. The first 3 should report that Autotools, Cmake, and Pin were install successfully, and the final should give the filename for the environment script.

#### `configure-morrigan.out`

`todo`

#### `install-morrigan.out`

`todo`

## Testing
To test this code, view the README in the `example` folder.

## Making Changes
After making changes to any of the submodules, re-run the `./install-morrigan.sh` script. You should _not_ need to run the `source` command again. 



## Making Changes
After making changes to any of the subprojects, re-run the `./install-morrigan.sh` script. You should not need to run `source` command again. 

## Workflow 
As mentioned above, this project relies on custom version of some other projects. If you want to make changes to those projects, you don't need to download them separately -- you can do that right from within this repo. Follow these steps to create changes and push them to our repos.

```
... todo ...
```


## Cleanup
A cleanup script, `cleanup.sh`, is provided to delete any files generated by any of the installation scripts.

## Related Work

1. TODO Cite Online Model Swapping paper
2. TODO Cite reference on phase detection
