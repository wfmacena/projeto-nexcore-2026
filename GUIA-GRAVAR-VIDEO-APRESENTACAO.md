# 🎥 GUIA - Como Gravar o Vídeo de Apresentação

## 🎯 Objetivo

Criar um vídeo de 8-15 minutos apresentando o projeto completo de forma profissional e demonstrativa.

**Prazo:** Gravar na semana da entrega (20-24/Nov)  
**Tempo estimado:** 3-4 horas (preparação + gravação + edição)

---

## 📋 ESPECIFICAÇÕES TÉCNICAS

### Requisitos:
- **Duração:** 8-15 minutos (ideal: 10-12 minutos)
- **Formato:** MP4 (H.264)
- **Resolução:** Mínimo 1280x720 (HD), ideal 1920x1080 (Full HD)
- **Áudio:** Claro e sem ruídos
- **Plataforma:** YouTube (não listado ou público)

### Não fazer:
- ❌ Vídeo muito curto (< 8 min) - parece incompleto
- ❌ Vídeo muito longo (> 15 min) - cansativo
- ❌ Áudio baixo ou com eco
- ❌ Tela tremendo ou desfocada
- ❌ Apenas ler slides (seja dinâmico!)

---

## 📝 ROTEIRO DETALHADO (12 minutos)

### ABERTURA (30 segundos)
**O que mostrar:**
```
Tela inicial com:
─────────────────────────────────────
    PROJETO DE INFRAESTRUTURA
       COMPUTACIONAL

       NexCore Tecnologia

    Integrantes: [Nomes]
         2026/2
─────────────────────────────────────
```

**O que falar:**
> "Olá, somos [nomes dos integrantes] e vamos apresentar nosso 
> Projeto de Infraestrutura Computacional para a empresa fictícia 
> NexCore Soluções em Tecnologia. O projeto integra 4 disciplinas: 
> Arquitetura, Sistemas Operacionais, Redes e IoT."

---

### 1. EMPRESA (1 minuto)
**O que mostrar:**
- Slide ou tela do `empresa/README.md`
- Organograma (se tiver)

**O que falar:**
> "A NexCore é uma empresa de tecnologia especializada em infraestrutura 
> de TI para logística, varejo e agronegócio. Opera com 1 matriz em 
> São Paulo e 2 filiais regionais em Campinas e Ribeirão Preto, 
> totalizando aproximadamente 300 funcionários.
> 
> O desafio foi projetar toda a infraestrutura computacional: hardware, 
> sistemas operacionais, redes e automação inteligente."

**Dica:** Seja breve, foque no essencial.

---

### 2. ARQUITETURA DE COMPUTADORES (2-3 minutos)
**O que mostrar:**
- Slide ou tela com os 3 perfis
- Tabela de configurações
- Fotos de produtos (opcional)

**O que falar:**
> "Na disciplina de Arquitetura, definimos 3 perfis de computadores:
> 
> **Perfil Administrativo** (108 unidades): i3-13100, 16GB RAM, SSD 512GB
> para áreas de escritório como RH, Financeiro e Comercial.
> 
> **Perfil Operacional** (162 unidades): i5-13400, 32GB RAM, SSD 1TB + HD 2TB
> para Engenharia, NOC e Suporte, que operam 24x7.
> 
> **Perfil Especializado** (30 unidades): i7-13700K, 64GB DDR5, RTX 4060
> para Data Center, BI e Desenvolvimento.
> 
> Também dimensionamos 8 servidores incluindo AD, File Server, SQL Server 
> e cluster Hyper-V para virtualização.
> 
> Verificamos a compatibilidade entre todos os componentes: soquetes, 
> chipsets, consumo elétrico. O orçamento total foi de R$ 4,076 milhões."

**Dica:** Mostrar tabela com configurações enquanto fala.

---

### 3. SISTEMAS OPERACIONAIS (2-3 minutos)
**O que mostrar:**
- Slide com logos dos SOs
- Tabela de serviços por servidor
- Diagrama AD (se tiver)

**O que falar:**
> "Para Sistemas Operacionais, escolhemos:
> 
> **Windows Server 2022** na maioria dos servidores para rodar Active Directory, 
> DNS, DHCP, Hyper-V e SQL Server. Dois servidores usam **Ubuntu Server** para 
> backup e monitoramento (Veeam e Zabbix), reduzindo custos.
> 
> Nas estações, definimos **Windows 11 Pro** para administrativo, 
> **Windows 11 Enterprise LTSC** para operacional (mais estável), e 
> **Windows 11 Enterprise** com Microsoft 365 E3 para especializadas.
> 
> Configuramos políticas de segurança: senhas complexas de 12+ caracteres 
> expiração 90 dias, criptografia BitLocker, MFA com Authenticator.
> 
> A estratégia de backup usa Veeam com RPO de 4 horas e RTO de 2 horas.
> 
> O licenciamento para 3 anos totaliza R$ 6,6 milhões incluindo Microsoft 365, 
> SQL Server, CALs e outras ferramentas."

**Dica:** Mencionar que está tudo documentado no GitHub.

---

### 4. REDES DE COMPUTADORES + DEMO PACKET TRACER (2-3 minutos)
**O que mostrar:**
- Diagrama de topologia (ASCII ou visual)
- **ABRIR PACKET TRACER AO VIVO**
- Fazer ping inter-VLAN ao vivo

**O que falar:**
> "A infraestrutura de rede conecta os 3 locais através de MPLS L3VPN 
> com links de 500 Mbps para Campinas e 300 Mbps para Ribeirão. 
> Cada local tem Internet redundante (fibra principal + 4G/5G backup).
> 
> Na Matriz SP, configuramos 8 VLANs: MGMT para switches, Servidores, 
> Estações Admin, Engenharia, NOC, WiFi Corporativo e IoT.
> 
> O endereçamento IP segue o padrão 10.X.0.0/16 onde X é 10 (Matriz), 
> 20 (Campinas) ou 30 (Ribeirão).
> 
> **[ABRIR PACKET TRACER]**
> 
> Aqui no Cisco Packet Tracer, implementamos a topologia da Matriz SP. 
> Temos um roteador fazendo roteamento inter-VLAN, um switch com as VLANs 
> 20 e 30 configuradas, PCs administrativos na VLAN 30 e servidores na VLAN 20.
> 
> **[CLICAR NO PC-ADM01 → DESKTOP → COMMAND PROMPT]**
> 
> Vou fazer um ping de um PC administrativo (VLAN 30, IP 10.10.20.10) 
> para o servidor de arquivos (VLAN 20, IP 10.10.10.10)...
> 
> **[DIGITAR: ping 10.10.10.10]**
> 
> ...e vemos que recebemos resposta! Isso prova que o roteamento inter-VLAN 
> está funcionando. Pacotes de diferentes VLANs conseguem se comunicar 
> através do roteador.
> 
> O investimento em rede foi de R$ 3,45 milhões em 3 anos."

**Dica:** Praticar o ping antes de gravar!

---

### 5. INTERNET DAS COISAS + DEMO TINKERCAD (2-3 minutos)
**O que mostrar:**
- Slide explicando o problema
- **ABRIR TINKERCAD AO VIVO**
- Simular os 3 casos ao vivo

**O que falar:**
> "Para IoT, desenvolvemos um monitor de temperatura para a sala de servidores.
> O superaquecimento é uma das principais causas de falhas em hardware.
> 
> Criamos um circuito com Arduino Uno, sensor analógico TMP36 e 3 LEDs 
> que indicam o status:
> • LED Verde: Temperatura normal (< 28°C)
> • LED Amarelo: Alerta (28-35°C)
> • LED Vermelho piscando: Crítico (≥ 35°C)
> 
> **[ABRIR TINKERCAD NO NAVEGADOR]**
> 
> Aqui está o circuito montado no Tinkercad. Temos o Arduino conectado 
> ao breadboard, o sensor TMP36 com 3 pinos (VCC, OUT e GND), os 3 LEDs 
> com resistores de 220 ohms.
> 
> O código foi desenvolvido pela equipe em C++ sem bibliotecas externas.
> 
> **[CLICAR EM START SIMULATION]**
> 
> Vou demonstrar os 3 casos:
> 
> **[CLICAR NO TMP36, AJUSTAR PARA 24°C]**
> Temperatura de 24°C... LED VERDE aceso. Tudo normal!
> 
> **[AJUSTAR PARA 30°C]**
> Agora 30°C... LED AMARELO aceso. Estado de alerta, ar-condicionado 
> deve ser verificado.
> 
> **[AJUSTAR PARA 37°C]**
> E a 37°C... LED VERMELHO piscando! Situação crítica, precisa intervenção 
> imediata.
> 
> **[ABRIR SERIAL MONITOR]**
> O Serial Monitor mostra os logs em tempo real com a temperatura e o status.
> 
> Esse sistema pode ser replicado com Arduino + Ethernet enviando alertas 
> via MQTT para o Zabbix do NOC."

**Dica:** Ter o Tinkercad já aberto em outra aba para não perder tempo carregando.

---

### 6. CONCLUSÃO (1 minuto)
**O que mostrar:**
- Slide com resumo financeiro
- Slide final com logos/agradecimento

**O que falar:**
> "O projeto integrou as 4 disciplinas de forma coerente:
> • Hardware suporta os sistemas operacionais
> • Sistemas rodam os serviços de rede
> • Rede conecta os sensores IoT
> • IoT monitora o ambiente do hardware
> 
> O investimento total em 3 anos é de R$ 14,2 milhões, incluindo hardware, 
> licenças e infraestrutura de rede. Para uma empresa de tecnologia com 
> 300 funcionários, esse investimento garante uma base sólida para crescimento.
> 
> Toda a documentação está no nosso GitHub, incluindo o arquivo do Packet Tracer 
> e o link do Tinkercad para testes.
> 
> Obrigado pela atenção!"

---

## 🎬 PREPARAÇÃO PARA GRAVAÇÃO

### Antes de gravar:

1. **Teste seu setup:**
   - [ ] Microfone funcionando (sem ruído)
   - [ ] Webcam ou captura de tela funcionando
   - [ ] Iluminação adequada (se mostrar rosto)
   - [ ] Internet estável

2. **Prepare os materiais:**
   - [ ] Slides prontos (PowerPoint/Google Slides)
   - [ ] Packet Tracer aberto com o projeto
   - [ ] Tinkercad aberto em aba do navegador
   - [ ] GitHub aberto para mostrar estrutura
   - [ ] Roteiro impresso ou em segunda tela

3. **Ensaie:**
   - [ ] Ler roteiro em voz alta (cronometrar)
   - [ ] Praticar transições entre telas
   - [ ] Praticar demonstrações (Packet Tracer + Tinkercad)
   - [ ] Ajustar tempo se passar de 15 minutos

---

## 🛠️ FERRAMENTAS DE GRAVAÇÃO

### Opção 1: OBS Studio (RECOMENDADO)
**Download:** https://obsproject.com

**Prós:**
- ✅ Gratuito e open-source
- ✅ Captura tela + webcam + áudio
- ✅ Controle total de qualidade
- ✅ Grava direto em MP4

**Como usar:**
1. Baixar e instalar OBS Studio
2. Configurar:
   - Scene: Adicionar "Display Capture" (tela inteira)
   - Audio: Selecionar microfone
   - (Opcional) Adicionar "Video Capture Device" (webcam no canto)
3. Settings → Output:
   - Output Mode: Simple
   - Recording Quality: High Quality
   - Recording Format: MP4
4. Clicar em "Start Recording"
5. Apresentar conforme roteiro
6. Clicar em "Stop Recording"

---

### Opção 2: Windows + PowerPoint
**Como usar:**
1. Abrir PowerPoint com slides
2. Slideshow → Record Slide Show
3. Selecionar "Record from Beginning"
4. Apresentar (pode alternar entre slides e outras janelas)
5. File → Export → Create a Video

**Limitações:**
- Menos controle de qualidade
- Difícil alternar para Packet Tracer/Tinkercad

---

### Opção 3: Zoom (Gravar reunião)
**Como usar:**
1. Criar reunião Zoom (sozinho)
2. Clicar em "Record" (gravar na nuvem ou localmente)
3. Compartilhar tela
4. Apresentar
5. Parar gravação

**Prós:**
- ✅ Fácil de usar
- ✅ Boa qualidade

**Contras:**
- ❌ Limitação de 40 min (plano gratuito)
- ❌ Marca d'água (plano gratuito)

---

## ✂️ EDIÇÃO BÁSICA

### Se precisar editar:

**Ferramenta recomendada:** DaVinci Resolve (gratuito)
**Download:** https://www.blackmagicdesign.com/products/davinciresolve

**Edições básicas:**
- Cortar início/fim (silêncios, erros)
- Adicionar texto/legenda na abertura
- Ajustar áudio (normalizar volume)
- Adicionar transições suaves

**Ferramenta alternativa:** Windows Video Editor (nativo Win 10/11)

---

## 📤 UPLOAD NO YOUTUBE

### Passo a passo:

1. **Acessar YouTube Studio:**
   - www.youtube.com/upload

2. **Upload do vídeo:**
   - Arrastar arquivo MP4
   - Aguardar processamento

3. **Configurações:**
   - **Título:** "Projeto Infraestrutura Computacional - NexCore Tecnologia"
   - **Descrição:**
     ```
     Projeto integrado de Infraestrutura Computacional para a empresa 
     fictícia NexCore Soluções em Tecnologia Ltda.
     
     Disciplinas:
     1. Arquitetura e Organização de Computadores
     2. Sistemas Operacionais
     3. Redes de Computadores
     4. Internet das Coisas (IoT)
     
     GitHub: [URL]
     Tinkercad: [URL]
     
     Integrantes:
     - [Nome1]
     - [Nome2]
     - [Nome3]
     
     Professor: Felipe Santos de Jesus
     Ano: 2026
     ```
   - **Visibilidade:** **Não listado** (ou Público)
   - **Miniatura:** Criar uma imagem com logo NexCore
   - **Playlist:** (opcional) Criar "Projeto 2026"

4. **Publicar:**
   - Clicar em "Publish"
   - Copiar URL do vídeo
   - Adicionar no PDF

---

## ✅ CHECKLIST PRÉ-GRAVAÇÃO

### Equipamento:
- [ ] Microfone testado (sem eco, sem ruído)
- [ ] Webcam testada (se for usar)
- [ ] Iluminação adequada
- [ ] Fones de ouvido (evita eco)

### Software:
- [ ] OBS/Zoom instalado e configurado
- [ ] Packet Tracer aberto com projeto
- [ ] Tinkercad aberto no navegador
- [ ] GitHub aberto
- [ ] Slides prontos

### Ambiente:
- [ ] Ambiente silencioso (sem TV, barulho de fundo)
- [ ] Porta fechada
- [ ] Notificações desligadas
- [ ] Celular no silencioso

### Conteúdo:
- [ ] Roteiro impresso ou visível
- [ ] Tempo ensaiado (8-15 min)
- [ ] Demonstrações práticadas
- [ ] Transições suaves planejadas

---

## 💡 DICAS FINAIS

### Durante a gravação:
1. **Fale com clareza** e num ritmo moderado
2. **Seja natural**, não precisa ser perfeito
3. **Mostre entusiasmo** pelo projeto
4. **Pause entre tópicos** (facilita edição)
5. **Se errar:** Pause, respire, refaça a frase

### O que NÃO fazer:
- ❌ Ler slides palavra por palavra
- ❌ Falar muito rápido (nervosismo)
- ❌ Gírias ou linguagem informal demais
- ❌ Ficar em silêncio por muito tempo
- ❌ Esquecer de demonstrar ao vivo

### O que fazer:
- ✅ Explicar com suas palavras
- ✅ Apontar na tela o que está falando
- ✅ Demonstrar funcionamento (Packet Tracer, Tinkercad)
- ✅ Conectar as disciplinas (mostrar integração)
- ✅ Finalizar com impacto (resumo + agradecimento)

---

## 🎯 RESULTADO ESPERADO

Vídeo final com:
- ✅ 10-12 minutos de duração
- ✅ Áudio claro e profissional
- ✅ Demonstrações ao vivo (Packet Tracer + Tinkercad)
- ✅ Explicação clara e didática
- ✅ Integração das 4 disciplinas
- ✅ Upload no YouTube (não listado)
- ✅ Link funcionando

**BOA SORTE NA GRAVAÇÃO! 🎥🎬**

---

## 📞 TROUBLESHOOTING

**Problema:** Áudio com eco
**Solução:** Usar fones de ouvido, afastar microfone da parede

**Problema:** Vídeo fica grande (> 2GB)
**Solução:** Exportar em 720p ao invés de 1080p

**Problema:** Packet Tracer trava durante gravação
**Solução:** Fechar outros programas, salvar projeto antes

**Problema:** Passou de 15 minutos
**Solução:** Ser mais objetivo em Arquitetura e SO (1,5-2min cada)

**Problema:** YouTube não aceita upload
**Solução:** Verificar se conta está verificada (SMS), esperar processamento
