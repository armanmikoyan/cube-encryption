# Cube Encryption

A custom encryption algorithm inspired by 3D cube rotations and positional transformations.

---

## About

Cube Encryption encodes data by mapping and rotating characters across multiple cube layers, creating complex encryption patterns that are difficult to reverse without the correct key.

Rather than relying on standard mathematical operations, the algorithm models a 3D cube where each face, layer, and position plays a role in transforming the input. Characters are placed into the cube structure and shifted through a series of rotations — both per-layer and cross-layer — producing a ciphertext that reflects the geometry of the cube itself.

Decryption is only possible by applying the rotations in reverse with the exact same key, making brute-force reversal computationally expensive without knowledge of the cube configuration.

---

## How It Works

1. **Mapping** — Input characters are distributed across the cube's positions, layer by layer
2. **Rotation** — Each layer is rotated based on key-derived parameters
3. **Cross-layer Transformation** — Characters shift between layers according to the cube's face relationships
4. **Output** — The final positions of all characters form the encrypted output

Decryption reverses each step using the same key, restoring the original data.

---

## Key Properties

| Property         | Description                                               |
|------------------|-----------------------------------------------------------|
| Algorithm type   | Symmetric (same key encrypts and decrypts)                |
| Structure        | 3D cube with multiple layers                              |
| Transformation   | Positional rotation across cube faces and layers          |
| Key sensitivity  | Any change in key produces a completely different result  |
| Custom design    | Not based on AES, RSA, or any standard cipher             |

---

## Build & Run
```bash
g++ main.cpp cube.cpp -o cube_encryption
./cube_encryption
```

---

## Usage
```cpp
std::string plaintext = "Hello, World!";
std::string key       = "mySecretKey";

std::string encrypted = CubeEncrypt(plaintext, key);
std::string decrypted = CubeDecrypt(encrypted, key);
```
