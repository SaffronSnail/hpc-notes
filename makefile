	IRECTORIES=$(wildcard */)

.PHONY: pdfs

combined.pdf: pdfs
	pdftk **/*.pdf cat output $@

pdfs:
	for d in ${DIRECTORIES}; do\
		cd $$d;\
		pdflatex main.tex;\
		cd ..;\
	done

clean:
	$(RM) all-notes.{aux,log,pdf,sta}

