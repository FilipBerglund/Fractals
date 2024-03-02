# Fractals


## Dependences
```{bash}
sudo apt-get install libsfml-dev
```

## Install
Install by running
```{bash}
make
```

## Play
```{bash}
make run
```


## It doesn't work! HELP!

### Error 0:
If you have this error
```bash
X Error of failed request:  BadValue (integer parameter out of range for operation)
  Major opcode of failed request:  154 (GLX)
  Minor opcode of failed request:  24 (X_GLXCreateNewContext)
  Value in failed request:  0x0
  Serial number of failed request:  29
  Current serial number in output stream:  30
```

and this
```bash
$ nvidia-smi
Failed to initialize NVML: Driver/library version mismatch
```
then try rebooting.

