# Gemeinsame Debug-Regeln fuer alle Makefiles.
# Einbinden am Ende eines Makefiles mit:  include ../debug.mk  (bzw. ../../debug.mk)
#
# Verwendung:  make debug-<Programmname>   z.B.  make debug-const
# Baut das Programm und startet es im Debugger (lldb auf macOS, sonst gdb).
# Anderer Debugger:  make debug-const DEBUGGER="gdb --tui --args"

ifeq ($(OS),Windows_NT)
  DEBUGGER ?= gdb --args
else ifeq ($(shell uname),Darwin)
  DEBUGGER ?= lldb --
else
  DEBUGGER ?= gdb --args
endif

# Shared Libraries (libnamesarchive.so) im aktuellen Ordner finden (Linux)
export LD_LIBRARY_PATH := .:$(LD_LIBRARY_PATH)

debug-%: %
	$(DEBUGGER) ./$*.out
