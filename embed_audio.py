from pathlib import Path

audio_folder = Path("Audio")

for wav_file in audio_folder.glob("*.wav"):

    name = wav_file.stem.lower()
    data = wav_file.read_bytes()

    output_file = Path(f"{name}.h")

    with open(output_file, "w") as file:

        file.write(f"#ifndef {name.upper()}_H\n")
        file.write(f"#define {name.upper()}_H\n\n")

        file.write(f"const unsigned char {name}Data[] = {{\n")

        for i, byte in enumerate(data):

            if i % 12 == 0:
                file.write("    ")

            file.write(f"0x{byte:02X}, ")

            if i % 12 == 11:
                file.write("\n")

        file.write("\n};\n\n")

        file.write(
            f"const unsigned int {name}DataSize = sizeof({name}Data);\n\n"
        )

        file.write("#endif\n")

    print(f"Embedded {wav_file} -> {output_file}")