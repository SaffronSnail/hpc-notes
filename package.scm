(define-module (saffronsnail hpc-notes pi)
  #:use-module (guix packages)
)

(package
  (name "hpc notes")
  (version "0.3")
  (source (origin (uri (string-append "file://" (getcwd)))
                  (method url-fetch)
                  (sha256 (system "guix hash -r ."))
          )
  )
  (build-system 
