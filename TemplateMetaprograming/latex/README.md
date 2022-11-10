
## Table of contents
Overall, our report contains 5 chapters in total:

- Template and metafunctions
- Polymporphism
- Concepts
- Experiment
- Conclusion

## Usage
To compile the report by docker, you need to install docker on your computer. After that, you can run the following command to compile the report:

```bash
docker run --rm -it -v $(pwd):/workdir danteev/texlive latexmk -pdf main.tex
```