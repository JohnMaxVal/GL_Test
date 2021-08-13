# GL_Test
1) In ChildProcess folder run: make -> logger
2) In ParentProcess folder run: make -> starter
3) From console run: ./starter <input_time> || make run
4)* All the termination of child process and killing of parent process should be done from ParentProcess folder
  4.1) Terminate child process: make term_child
  4.2) Kill parent: make kill_parent
