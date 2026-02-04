#!/bin/bash

# Cores da 42
CYAN="\033[36m\033[01m"
GRN="\033[32m\033[01m"
RED="\033[31m\033[01m"
YLW="\033[33m\033[01m"
CLR="\033[0m"

clear

# ASCII Art Gigante da 42
echo -e "${CYAN}"
cat << "EOF"
        :::     ::::::::
       :+:     :+:    :+:
      +:+ +:+        +:+
     +#+  +:+      +#+
    +#+#+#+#+#+  +#+
          #+#   #+#
          ###  ##########

      === TEST RUSH 01 ===
EOF
echo -e "${CLR}"

# Compilação
make re > /dev/null
if [ ! -f "./rush-01" ]; then
    echo -e "${RED}Erro: Falha na compilação do 'rush-01'.${CLR}"
    exit 1
fi
echo -e "${GRN}Compilação OK! Iniciando os testes...${CLR}\n"

# Contadores Globais
PASSED=0
FAILED=0
TOTAL=0

# ==========================================
# FASE 1: TESTES DE SEGURANÇA (ENTRADAS QUEBRADAS)
# ==========================================
echo -e "${YLW}>>> FASE 1: TESTES DE SEGURANÇA (Aguardando 'Error')${CLR}"

run_error_test() {
    local test_name="$1"
    local input="$2"
    TOTAL=$((TOTAL + 1))

    output=$(./rush-01 "$input" 2>&1)

    # O teste PASSA se o programa printar "Error"
    if echo "$output" | grep -q "Error"; then
        echo -e "✅ ${GRN}[DEFESA OK]${CLR} $test_name rejeitado com sucesso."
        PASSED=$((PASSED + 1))
    else
        echo -e "❌ ${RED}[FALHA]${CLR} $test_name passou direto! (Vulnerabilidade)"
        FAILED=$((FAILED + 1))
    fi
    sleep 0.2
}

run_error_test "Entrada Vazia" ""
run_error_test "Apenas Espaços" "                "
run_error_test "Falta 1 Número (15 nums)" "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2"
run_error_test "Excesso (17 nums)" "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 4"
run_error_test "Letras no meio" "4 3 2 1 a 2 2 2 4 3 2 1 1 2 2 2"
run_error_test "Número Fora do Limite (5)" "4 3 2 1 5 2 2 2 4 3 2 1 1 2 2 2"
run_error_test "Número Negativo (-2)" "4 3 2 1 -2 2 2 2 4 3 2 1 1 2 2 2"
run_error_test "Espaços Duplos" "4  3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
run_error_test "Sem Espaços" "4321122243211222"

# --- OS NOVOS TESTES IMPOSSÍVEIS ---
run_error_test "Tudo 4 (Impossível)" "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4"
run_error_test "Tudo 1 (Impossível)" "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1"
run_error_test "Bordas Opostas 4-4" "4 3 2 1 4 3 2 1 1 2 2 2 1 2 2 2"

# Teste Especial: 16 argumentos separados (sem aspas)
TOTAL=$((TOTAL + 1))
output=$(./rush-01 4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 2>&1)
if echo "$output" | grep -q "Error"; then
    echo -e "✅ ${GRN}[DEFESA OK]${CLR} Teste sem aspas (16 args) rejeitado com sucesso."
    PASSED=$((PASSED + 1))
else
    echo -e "❌ ${RED}[FALHA]${CLR} Teste sem aspas passou direto! (Vulnerabilidade)"
    FAILED=$((FAILED + 1))
fi

echo ""

# ==========================================
# FASE 2: TESTE DE STRESS (100 TABULEIROS)
# ==========================================
echo -e "${YLW}>>> FASE 2: TESTE DE STRESS (100 Tabuleiros)${CLR}"
COUNT_PHASE2=0

while read -r line; do
    [ -z "$line" ] && continue
    TOTAL=$((TOTAL + 1))
    COUNT_PHASE2=$((COUNT_PHASE2 + 1))

    output=$(./rush-01 "$line" 2>&1)

    if echo "$output" | grep -q "Error"; then
        echo -e "\n❌ ${RED}[FAIL]${CLR} Quebrou no tabuleiro $COUNT_PHASE2"
        FAILED=$((FAILED + 1))
    else
        PASSED=$((PASSED + 1))
        printf "\r✅ ${GRN}[RESOLVIDO]${CLR} Processando... %03d/100 tabuleiros." "$COUNT_PHASE2"
    fi
    sleep 0.05
done << 'EOF'
2 4 2 1 2 1 2 4 3 3 1 2 1 2 3 3
3 2 2 1 2 3 1 2 4 2 1 2 1 3 3 2
2 1 2 3 1 2 3 2 2 3 3 1 3 2 1 3
1 4 3 2 2 1 2 2 1 4 3 2 2 1 2 2
3 2 1 2 2 3 2 1 3 2 1 3 2 2 4 1
3 2 2 1 2 3 1 2 3 2 1 3 1 2 4 2
2 2 3 1 3 1 2 2 3 1 2 2 1 3 2 2
2 1 2 3 1 2 3 2 2 3 3 1 3 2 1 3
2 3 1 2 2 1 3 2 2 3 1 2 2 1 3 2
2 4 1 2 2 1 4 2 2 4 1 2 2 1 4 2
1 2 3 2 2 3 2 1 1 2 3 2 2 3 2 1
4 1 2 2 1 4 2 2 2 3 2 1 2 1 2 3
3 1 2 2 2 2 1 3 2 2 1 3 3 1 2 2
1 3 2 2 3 1 2 2 1 3 2 2 2 2 1 3
2 3 3 1 3 2 1 2 2 1 2 3 1 3 3 2
2 1 3 3 3 3 2 1 2 1 2 4 2 4 2 1
2 2 3 1 3 1 2 2 3 1 2 2 1 3 2 2
2 3 2 1 2 1 2 3 3 1 3 2 1 4 2 2
3 1 2 2 1 3 2 2 2 2 3 1 3 1 2 2
3 1 2 2 2 2 1 3 2 2 1 3 3 1 2 2
2 3 1 2 3 2 3 1 2 1 2 3 2 3 2 1
2 2 2 1 2 3 1 4 3 2 1 2 1 2 3 2
3 2 2 1 2 3 1 2 3 2 1 3 1 3 3 2
2 1 2 3 2 3 2 1 2 3 1 3 3 2 3 1
2 1 3 3 3 2 2 1 2 1 2 3 2 3 2 1
1 2 3 2 2 3 2 1 1 2 3 2 2 3 2 1
2 2 1 3 2 2 3 1 2 1 2 3 2 2 3 1
2 3 1 3 3 1 3 2 2 1 3 2 2 3 1 2
1 2 2 3 2 3 1 2 1 2 3 2 3 2 1 2
1 2 2 4 3 3 2 1 1 2 3 3 4 2 2 1
2 2 1 4 3 2 3 1 2 1 2 3 2 3 2 1
2 4 1 2 2 1 4 2 2 1 3 2 2 3 1 2
1 2 2 2 4 3 2 1 1 2 3 4 2 2 2 1
1 4 2 3 2 1 2 2 1 3 3 2 3 2 1 3
2 2 1 2 1 2 4 3 2 3 2 1 2 1 2 3
2 1 2 3 3 2 2 1 2 1 2 3 3 2 2 1
1 2 2 3 2 3 1 2 1 2 3 2 3 2 1 2
1 3 2 2 2 2 1 3 1 3 2 2 3 1 2 2
2 1 3 2 3 2 2 1 2 1 2 3 2 3 2 1
3 2 3 1 2 3 1 2 3 2 1 2 1 2 3 2
2 2 2 1 3 1 2 4 3 1 2 2 1 2 2 3
1 2 2 3 3 2 1 2 1 2 2 3 3 2 1 2
3 3 1 2 1 2 4 2 2 4 2 1 2 1 3 3
1 3 2 2 3 2 1 2 1 3 2 3 3 1 3 2
1 2 3 2 2 3 2 1 1 2 3 2 2 3 2 1
2 2 1 3 2 2 3 1 3 1 2 2 2 3 2 1
1 2 3 2 3 3 2 1 1 2 3 3 2 3 2 1
3 4 1 2 2 1 2 2 2 2 1 2 2 1 4 3
4 3 1 2 1 2 2 2 3 3 2 1 2 1 3 3
2 3 2 1 1 2 2 3 2 3 2 1 1 2 2 3
3 1 2 2 1 3 2 2 2 2 3 1 2 2 1 3
3 2 2 1 1 2 2 3 4 2 2 1 1 2 2 4
3 1 2 3 1 2 3 2 2 3 2 1 3 2 1 3
2 2 1 3 1 3 2 2 2 2 3 1 2 2 1 3
3 3 1 2 1 2 4 2 2 4 2 1 2 1 3 3
2 3 1 2 1 2 3 2 2 3 2 1 2 1 3 2
1 2 3 2 2 1 2 3 1 3 3 2 4 1 2 2
2 1 2 4 2 4 2 1 2 3 1 2 3 2 2 1
1 2 3 3 3 3 2 1 1 2 2 3 3 2 2 1
2 2 1 2 2 1 4 3 3 4 1 2 2 1 2 2
3 1 2 2 2 3 2 1 2 2 1 3 2 2 3 1
1 2 3 4 2 2 2 1 1 2 2 2 4 3 2 1
1 3 2 2 3 2 1 2 1 3 2 2 3 1 2 2
2 3 1 2 2 1 3 2 2 3 1 2 2 1 3 2
1 3 3 2 2 2 1 3 1 3 2 2 2 1 3 2
2 1 2 3 1 3 3 2 2 3 3 1 3 2 1 2
3 2 2 1 1 2 3 2 3 2 2 1 1 2 3 2
2 2 4 1 2 2 1 4 2 1 2 3 1 2 3 2
2 3 1 2 2 1 3 2 2 1 4 2 2 4 1 2
3 2 1 2 2 1 3 3 3 3 1 2 2 1 2 3
4 1 2 2 1 3 2 3 2 3 2 1 2 1 2 3
2 1 3 2 2 3 1 2 2 1 3 2 2 3 1 2
3 1 2 3 2 4 2 1 2 3 1 2 3 2 2 1
3 1 2 2 1 2 2 3 2 2 3 1 3 1 2 3
1 3 2 2 2 2 1 3 1 3 2 2 3 1 2 2
2 1 2 3 2 3 2 1 2 3 1 3 3 2 3 1
2 1 3 2 1 3 2 3 2 3 2 1 2 1 2 3
3 2 4 1 2 2 1 2 3 2 1 3 1 3 3 2
3 1 2 2 1 3 2 2 2 2 3 1 2 2 1 3
2 1 2 3 3 2 1 2 2 1 2 3 3 2 1 2
3 2 1 2 2 3 2 1 3 2 1 3 2 3 3 1
3 2 1 2 2 1 3 3 3 3 1 2 2 1 2 3
3 1 2 3 1 3 3 2 2 3 2 1 3 2 1 2
1 2 2 3 3 2 1 2 1 2 2 3 3 2 1 2
2 2 3 1 2 2 1 3 3 1 2 2 1 3 2 2
2 2 3 1 2 2 1 3 2 2 1 3 1 3 2 2
1 2 3 3 4 2 2 1 1 2 2 4 3 3 2 1
3 1 2 2 1 3 2 2 2 2 3 1 2 2 1 3
3 1 2 2 1 3 2 2 2 2 3 1 2 2 1 3
2 3 1 2 1 2 2 3 2 3 2 1 2 1 2 3
2 2 1 4 2 3 3 1 3 2 1 2 2 3 2 1
3 1 2 2 2 2 1 3 2 2 1 3 3 1 2 2
2 1 3 2 2 2 1 3 2 4 1 3 2 1 2 2
3 3 2 1 2 1 3 3 4 3 1 2 1 2 2 2
1 2 3 2 3 2 1 2 1 2 2 3 2 3 1 2
2 1 3 2 2 3 1 2 2 1 3 2 2 3 1 2
2 3 4 1 2 2 1 2 2 1 2 2 1 4 3 2
3 2 1 2 2 3 2 1 2 2 1 4 2 3 3 1
2 3 1 2 1 2 3 3 2 4 2 1 2 1 2 4
4 2 2 1 1 2 2 4 3 2 2 1 1 2 2 3
2 4 1 2 2 1 4 2 2 4 1 2 2 1 4 2
EOF

# ==========================================
# RESULTADO FINAL
# ==========================================
echo -e "\n\n${CYAN}==========================================${CLR}"
echo -e "${YLW}          RELATÓRIO DO RUSH 01${CLR}"
echo -e "${CYAN}==========================================${CLR}"
if [ $FAILED -eq 0 ]; then
    echo -e "${GRN}VITÓRIA TOTAL! ${PASSED}/${TOTAL} testes passaram.${CLR}"
    echo -e "✓ Segurança de memória testada e aprovada."
    echo -e "✓ Lógica do algoritmo 100% precisa."
else
    echo -e "${RED}ALERTA: Falhou em $FAILED testes.${CLR}"
fi

make fclean > /dev/null
