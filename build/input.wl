VARINT a 1
VARINT b 2
VARINT c 3
VARLIST d a b c
VARLIST e d a b c
VARLIST f e d a b c
GET g 0 f
GET h 0 e
COPY i h
COPY j h
COMBINE i j
SET -1 1 d
COPY i g
CHS a
ADD b c
VARINT z 0
IF z 18
HLT
VARINT v 1
VARINT q -5
IF q 23
ADD q v
GOTO 20
HLT