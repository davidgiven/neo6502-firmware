;
;	This file is automatically generated.
;
	.section code
BinaryTokenText:
	.byte	$01,$ab                       	; $ 20 +
	.byte	$01,$ad                       	; $ 21 -
	.byte	$01,$aa                       	; $ 22 *
	.byte	$01,$af                       	; $ 23 /
	.byte	$02,$3e,$be                   	; $ 24 >>
	.byte	$02,$3c,$bc                   	; $ 25 <<
	.byte	$01,$a5                       	; $ 26 %
	.byte	$01,$dc                       	; $ 27 \
	.byte	$01,$a6                       	; $ 28 &
	.byte	$01,$fc                       	; $ 29 |
	.byte	$01,$de                       	; $ 2a ^
	.byte	$01,$be                       	; $ 2b >
	.byte	$02,$3e,$bd                   	; $ 2c >=
	.byte	$01,$bc                       	; $ 2d <
	.byte	$02,$3c,$bd                   	; $ 2e <=
	.byte	$02,$3c,$be                   	; $ 2f <>
	.byte	$01,$bd                       	; $ 30 =
	.byte	$FF

BaseTokenText:
	.byte	$00                           	; $ 80 
	.byte	$01,$a4                       	; $ 81 $
	.byte	$01,$a8                       	; $ 82 (
	.byte	$05,$52,$41,$4e,$44,$a8       	; $ 83 RAND(
	.byte	$04,$52,$4e,$44,$a8           	; $ 84 RND(
	.byte	$06,$49,$53,$56,$41,$4c,$a8   	; $ 85 ISVAL(
	.byte	$04,$49,$4e,$54,$a8           	; $ 86 INT(
	.byte	$05,$54,$49,$4d,$45,$a8       	; $ 87 TIME(
	.byte	$06,$45,$56,$45,$4e,$54,$a8   	; $ 88 EVENT(
	.byte	$07,$49,$4e,$4b,$45,$59,$24,$a8	; $ 89 INKEY$(
	.byte	$04,$41,$53,$43,$a8           	; $ 8a ASC(
	.byte	$05,$43,$48,$52,$24,$a8       	; $ 8b CHR$(
	.byte	$04,$53,$51,$52,$a8           	; $ 8c SQR(
	.byte	$04,$4c,$45,$4e,$a8           	; $ 8d LEN(
	.byte	$04,$41,$42,$53,$a8           	; $ 8e ABS(
	.byte	$04,$53,$47,$4e,$a8           	; $ 8f SGN(
	.byte	$04,$56,$41,$4c,$a8           	; $ 90 VAL(
	.byte	$05,$53,$54,$52,$24,$a8       	; $ 91 STR$(
	.byte	$05,$4d,$49,$44,$24,$a8       	; $ 92 MID$(
	.byte	$06,$4c,$45,$46,$54,$24,$a8   	; $ 93 LEFT$(
	.byte	$07,$52,$49,$47,$48,$54,$24,$a8	; $ 94 RIGHT$(
	.byte	$04,$53,$49,$4e,$a8           	; $ 95 SIN(
	.byte	$04,$43,$4f,$53,$a8           	; $ 96 COS(
	.byte	$04,$54,$41,$4e,$a8           	; $ 97 TAN(
	.byte	$05,$41,$54,$41,$4e,$a8       	; $ 98 ATAN(
	.byte	$04,$4c,$4f,$47,$a8           	; $ 99 LOG(
	.byte	$04,$45,$58,$50,$a8           	; $ 9a EXP(
	.byte	$04,$4b,$45,$59,$a8           	; $ 9b KEY(
	.byte	$05,$50,$45,$45,$4b,$a8       	; $ 9c PEEK(
	.byte	$05,$44,$45,$45,$4b,$a8       	; $ 9d DEEK(
	.byte	$06,$41,$4c,$4c,$4f,$43,$a8   	; $ 9e ALLOC(
	.byte	$04,$4d,$41,$58,$a8           	; $ 9f MAX(
	.byte	$04,$4d,$49,$4e,$a8           	; $ a0 MIN(
	.byte	$04,$48,$49,$54,$a8           	; $ a1 HIT(
	.byte	$00                           	; $ a2 
	.byte	$00                           	; $ a3 
	.byte	$00                           	; $ a4 
	.byte	$00                           	; $ a5 
	.byte	$00                           	; $ a6 
	.byte	$00                           	; $ a7 
	.byte	$00                           	; $ a8 
	.byte	$00                           	; $ a9 
	.byte	$00                           	; $ aa 
	.byte	$00                           	; $ ab 
	.byte	$00                           	; $ ac 
	.byte	$00                           	; $ ad 
	.byte	$00                           	; $ ae 
	.byte	$00                           	; $ af 
	.byte	$05,$57,$48,$49,$4c,$c5       	; $ b0 WHILE
	.byte	$04,$57,$45,$4e,$c4           	; $ b1 WEND
	.byte	$02,$49,$c6                   	; $ b2 IF
	.byte	$05,$45,$4e,$44,$49,$c6       	; $ b3 ENDIF
	.byte	$02,$44,$cf                   	; $ b4 DO
	.byte	$04,$4c,$4f,$4f,$d0           	; $ b5 LOOP
	.byte	$06,$52,$45,$50,$45,$41,$d4   	; $ b6 REPEAT
	.byte	$05,$55,$4e,$54,$49,$cc       	; $ b7 UNTIL
	.byte	$04,$50,$52,$4f,$c3           	; $ b8 PROC
	.byte	$07,$45,$4e,$44,$50,$52,$4f,$c3	; $ b9 ENDPROC
	.byte	$03,$46,$4f,$d2               	; $ ba FOR
	.byte	$04,$4e,$45,$58,$d4           	; $ bb NEXT
	.byte	$04,$43,$41,$53,$c5           	; $ bc CASE
	.byte	$07,$45,$4e,$44,$43,$41,$53,$c5	; $ bd ENDCASE
	.byte	$00                           	; $ be 
	.byte	$04,$54,$48,$45,$ce           	; $ bf THEN
	.byte	$00                           	; $ c0 
	.byte	$00                           	; $ c1 
	.byte	$00                           	; $ c2 
	.byte	$00                           	; $ c3 
	.byte	$02,$54,$cf                   	; $ c4 TO
	.byte	$03,$4c,$45,$d4               	; $ c5 LET
	.byte	$05,$50,$52,$49,$4e,$d4       	; $ c6 PRINT
	.byte	$05,$49,$4e,$50,$55,$d4       	; $ c7 INPUT
	.byte	$03,$53,$59,$d3               	; $ c8 SYS
	.byte	$04,$45,$58,$49,$d4           	; $ c9 EXIT
	.byte	$01,$ac                       	; $ ca ,
	.byte	$01,$bb                       	; $ cb ;
	.byte	$01,$ba                       	; $ cc :
	.byte	$01,$a7                       	; $ cd '
	.byte	$01,$a9                       	; $ ce )
	.byte	$04,$52,$45,$41,$c4           	; $ cf READ
	.byte	$04,$44,$41,$54,$c1           	; $ d0 DATA
	.byte	$04,$45,$4c,$53,$c5           	; $ d1 ELSE
	.byte	$04,$57,$48,$45,$ce           	; $ d2 WHEN
	.byte	$06,$44,$4f,$57,$4e,$54,$cf   	; $ d3 DOWNTO
	.byte	$04,$50,$4f,$4b,$c5           	; $ d4 POKE
	.byte	$04,$44,$4f,$4b,$c5           	; $ d5 DOKE
	.byte	$05,$4c,$4f,$43,$41,$cc       	; $ d6 LOCAL
	.byte	$04,$43,$41,$4c,$cc           	; $ d7 CALL
	.byte	$01,$a3                       	; $ d8 #
	.byte	$01,$ae                       	; $ d9 .
	.byte	$04,$4c,$49,$4e,$c5           	; $ da LINE
	.byte	$04,$52,$45,$43,$d4           	; $ db RECT
	.byte	$04,$4d,$4f,$56,$c5           	; $ dc MOVE
	.byte	$04,$50,$4c,$4f,$d4           	; $ dd PLOT
	.byte	$07,$45,$4c,$4c,$49,$50,$53,$c5	; $ de ELLIPSE
	.byte	$04,$54,$45,$58,$d4           	; $ df TEXT
	.byte	$FF

Shift1TokenText:
	.byte	$05,$43,$4c,$45,$41,$d2       	; $180 CLEAR
	.byte	$03,$4e,$45,$d7               	; $181 NEW
	.byte	$03,$52,$55,$ce               	; $182 RUN
	.byte	$04,$53,$54,$4f,$d0           	; $183 STOP
	.byte	$03,$45,$4e,$c4               	; $184 END
	.byte	$06,$41,$53,$53,$45,$52,$d4   	; $185 ASSERT
	.byte	$04,$4c,$49,$53,$d4           	; $186 LIST
	.byte	$04,$53,$41,$56,$c5           	; $187 SAVE
	.byte	$04,$4c,$4f,$41,$c4           	; $188 LOAD
	.byte	$03,$43,$41,$d4               	; $189 CAT
	.byte	$05,$47,$4f,$53,$55,$c2       	; $18a GOSUB
	.byte	$04,$47,$4f,$54,$cf           	; $18b GOTO
	.byte	$06,$52,$45,$54,$55,$52,$ce   	; $18c RETURN
	.byte	$07,$52,$45,$53,$54,$4f,$52,$c5	; $18d RESTORE
	.byte	$03,$44,$49,$cd               	; $18e DIM
	.byte	$04,$46,$4b,$45,$d9           	; $18f FKEY
	.byte	$03,$43,$4c,$d3               	; $190 CLS
	.byte	$03,$49,$4e,$cb               	; $191 INK
	.byte	$05,$46,$52,$41,$4d,$c5       	; $192 FRAME
	.byte	$05,$53,$4f,$4c,$49,$c4       	; $193 SOLID
	.byte	$02,$42,$d9                   	; $194 BY
	.byte	$03,$57,$48,$cf               	; $195 WHO
	.byte	$07,$50,$41,$4c,$45,$54,$54,$c5	; $196 PALETTE
	.byte	$04,$44,$52,$41,$d7           	; $197 DRAW
	.byte	$05,$49,$4d,$41,$47,$c5       	; $198 IMAGE
	.byte	$FF

Shift2TokenText:
	.byte	$03,$41,$44,$c3               	; $280 ADC
	.byte	$03,$41,$4e,$c4               	; $281 AND
	.byte	$03,$41,$53,$cc               	; $282 ASL
	.byte	$03,$42,$43,$c3               	; $283 BCC
	.byte	$03,$42,$43,$d3               	; $284 BCS
	.byte	$03,$42,$45,$d1               	; $285 BEQ
	.byte	$03,$42,$49,$d4               	; $286 BIT
	.byte	$03,$42,$4d,$c9               	; $287 BMI
	.byte	$03,$42,$4e,$c5               	; $288 BNE
	.byte	$03,$42,$50,$cc               	; $289 BPL
	.byte	$03,$42,$52,$c1               	; $28a BRA
	.byte	$03,$42,$52,$cb               	; $28b BRK
	.byte	$03,$42,$56,$c3               	; $28c BVC
	.byte	$03,$42,$56,$d3               	; $28d BVS
	.byte	$03,$43,$4c,$c3               	; $28e CLC
	.byte	$03,$43,$4c,$c4               	; $28f CLD
	.byte	$03,$43,$4c,$c9               	; $290 CLI
	.byte	$03,$43,$4c,$d6               	; $291 CLV
	.byte	$03,$43,$4d,$d0               	; $292 CMP
	.byte	$03,$43,$50,$d8               	; $293 CPX
	.byte	$03,$43,$50,$d9               	; $294 CPY
	.byte	$03,$44,$45,$c3               	; $295 DEC
	.byte	$03,$44,$45,$d8               	; $296 DEX
	.byte	$03,$44,$45,$d9               	; $297 DEY
	.byte	$03,$45,$4f,$d2               	; $298 EOR
	.byte	$03,$49,$4e,$c3               	; $299 INC
	.byte	$03,$49,$4e,$d8               	; $29a INX
	.byte	$03,$49,$4e,$d9               	; $29b INY
	.byte	$03,$4a,$4d,$d0               	; $29c JMP
	.byte	$03,$4a,$53,$d2               	; $29d JSR
	.byte	$03,$4c,$44,$c1               	; $29e LDA
	.byte	$03,$4c,$44,$d8               	; $29f LDX
	.byte	$03,$4c,$44,$d9               	; $2a0 LDY
	.byte	$03,$4c,$53,$d2               	; $2a1 LSR
	.byte	$03,$4e,$4f,$d0               	; $2a2 NOP
	.byte	$03,$4f,$52,$c1               	; $2a3 ORA
	.byte	$03,$50,$48,$c1               	; $2a4 PHA
	.byte	$03,$50,$48,$d0               	; $2a5 PHP
	.byte	$03,$50,$48,$d8               	; $2a6 PHX
	.byte	$03,$50,$48,$d9               	; $2a7 PHY
	.byte	$03,$50,$4c,$c1               	; $2a8 PLA
	.byte	$03,$50,$4c,$d0               	; $2a9 PLP
	.byte	$03,$50,$4c,$d8               	; $2aa PLX
	.byte	$03,$50,$4c,$d9               	; $2ab PLY
	.byte	$03,$52,$4f,$cc               	; $2ac ROL
	.byte	$03,$52,$4f,$d2               	; $2ad ROR
	.byte	$03,$52,$54,$c9               	; $2ae RTI
	.byte	$03,$52,$54,$d3               	; $2af RTS
	.byte	$03,$53,$42,$c3               	; $2b0 SBC
	.byte	$03,$53,$45,$c3               	; $2b1 SEC
	.byte	$03,$53,$45,$c4               	; $2b2 SED
	.byte	$03,$53,$45,$c9               	; $2b3 SEI
	.byte	$03,$53,$54,$c1               	; $2b4 STA
	.byte	$03,$53,$54,$d8               	; $2b5 STX
	.byte	$03,$53,$54,$d9               	; $2b6 STY
	.byte	$03,$53,$54,$da               	; $2b7 STZ
	.byte	$03,$54,$41,$d8               	; $2b8 TAX
	.byte	$03,$54,$41,$d9               	; $2b9 TAY
	.byte	$03,$54,$52,$c2               	; $2ba TRB
	.byte	$03,$54,$53,$c2               	; $2bb TSB
	.byte	$03,$54,$53,$d8               	; $2bc TSX
	.byte	$03,$54,$58,$c1               	; $2bd TXA
	.byte	$03,$54,$58,$d3               	; $2be TXS
	.byte	$03,$54,$59,$c1               	; $2bf TYA
	.byte	$03,$53,$54,$d0               	; $2c0 STP
	.byte	$FF

BinaryPrecedence:
	.byte	3		; +
	.byte	3		; -
	.byte	4		; *
	.byte	4		; /
	.byte	4		; >>
	.byte	4		; <<
	.byte	4		; %
	.byte	4		; \
	.byte	1		; &
	.byte	1		; |
	.byte	1		; ^
	.byte	2		; >
	.byte	2		; >=
	.byte	2		; <
	.byte	2		; <=
	.byte	2		; <>
	.byte	2		; =
	.send code
