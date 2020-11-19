((nil . ((cmake-ide-build-dir . "/home/alex/project/nodes-build")
         (cmake-ide-cmake-opts . "-DQt5_DIR=/home/alex/Qt/5.15.0/gcc_64/lib/cmake/Qt5")
         (eval . (setq projectile-project-compilation-cmd #'helm-make-projectile
                       projectile-project-compilation-dir "/home/alex/project/nodes-build"
                       helm-make-build-dir (projectile-compilation-dir)))
         (projectile-project-run-cmd . "./nodes")
         (projectile-project-configure-cmd . "cmake -DQt5_DIR=/home/alex/Qt/5.15.0/gcc_64/lib/cmake/Qt5 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ../nodes"))))
