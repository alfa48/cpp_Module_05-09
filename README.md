
---

# ✅ Método 1 (Mais simples e recomendado)

Suponha que:

* Repositório original: `https://github.com/usuario/projeto-antigo.git`
* Branch que você quer migrar: `feature-x`
* Novo repositório vazio: `https://github.com/usuario/projeto-novo.git`

### 1️⃣ Clone o repositório original

```bash
git clone https://github.com/usuario/projeto-antigo.git
cd projeto-antigo
```

### 2️⃣ Vá para a branch que deseja migrar

```bash
git checkout feature-x
```

### 3️⃣ Remova o remote antigo

```bash
git remote remove origin
```

### 4️⃣ Adicione o novo repositório vazio

```bash
git remote add origin https://github.com/usuario/projeto-novo.git
```

### 5️⃣ Envie a branch para o novo repositório

```bash
git push -u origin feature-x
```

✅ Isso vai levar **todo o histórico daquela branch**, exatamente como está.
