<report services status>
-bash-3.2$ svcs svc:/network/ssh:default
STATE          STIME    FMRI
online          8월_29 svc:/network/ssh:default

<report dependent services>
-bash-3.2$ svcs -d svc:/network/ssh:default
STATE          STIME    FMRI
online          8월_29 svc:/network/loopback:default
online          8월_29 svc:/network/physical:default
online          8월_29 svc:/system/cryptosvc:default
online          8월_29 svc:/system/filesystem/local:default
online          8월_29 svc:/system/utmp:default
online          8월_29 svc:/system/filesystem/autofs:default

-bash-3.2$ svcs -D svc:/network/ssh:default
STATE          STIME    FMRI
online          8월_29 svc:/milestone/multi-user-server:default

