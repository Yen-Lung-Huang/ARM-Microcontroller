### README for ARM-Microcontroller Repository

# ARM-Microcontroller

This repository is a collection of my personal notes and projects related to STM32, GD32, and MG32 microcontrollers. It is organized into three main directories and may not be fully complete.

## Repository Structure

- **STM32**
  - Contains projects and libraries for STM32 microcontrollers.
- **GD32**
  - Contains projects and libraries for GD32 microcontrollers.
- **MG32**
  - Contains projects and libraries for MG32 microcontrollers.

## Getting Started

### Prerequisites

To work with the projects in this repository, you may need:

- **Keil MDK**: Integrated Development Environment for ARM microcontrollers. [Download Keil MDK](https://www.keil.com/download/)
- **STM32CubeMX**: Optional but useful for generating initialization code for STM32. [Download STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)
- **STM32CubeIDE**: Alternative to Keil MDK that integrates CubeMX functionality. [Download STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
- **Visual Studio Code**: Useful for editing and debugging code, but not necessary. [Download VS Code](https://code.visualstudio.com/)

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/Yen-Lung-Huang/ARM-Microcontroller.git
   ```
2. Initialize submodules:
   ```bash
   cd ARM-Microcontroller
   git submodule update --init --recursive
   ```

### Project Setup

Refer to the [Notion Page](https://yen-lung-huang.notion.site/KEIL-MDK-6a0c48f6123f4da9a6e4cb1625dc8c88?pvs=4) for detailed instructions on setting up Keil projects and tips for efficient development.

## Tips and Best Practices

- **Using VS Code with Keil**: Enhances your coding and debugging experience. [Video Tutorial](https://www.youtube.com/watch?v=Kqx5ySmTHuw&t=53s).
- **Auto-Alignment in Keil**: Improves code readability. Use Artistic Style for formatting.
  1. Download Artistic Style.
  2. Copy `Astyle.exe` to the Keil installation directory.
  3. Configure Keil to use Artistic Style via the Tools menu.

## Troubleshooting

### Common Issues

- **[Keil MDK crashes with ST-Link debugger](https://www.notion.so/yen-lung-huang/KEIL-MDK-6a0c48f6123f4da9a6e4cb1625dc8c88?pvs=4#7eb312c2c7a2479a8b835e0fffe28675)**: Replace the `STLinkUSBDriver.dll` in your MDK installation directory.
- **[Invalid ROM Table error](https://www.notion.so/yen-lung-huang/KEIL-MDK-6a0c48f6123f4da9a6e4cb1625dc8c88?pvs=4#e15d1210f1704c99a78ca07336771146)**: Adjust settings in Keil.
- **[Runtime Error: HardFault_Handler](https://www.notion.so/yen-lung-huang/KEIL-MDK-6a0c48f6123f4da9a6e4cb1625dc8c88?pvs=4#51b0328136534345908d507c4b7c8aa9)**: Configure CubeMX Project Manager settings for heap and stack sizes.

## Contributing

We welcome contributions! Please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add new feature'`).
5. Push to the branch (`git push origin feature-branch`).
6. Open a pull request.

## Contact

For any questions or suggestions, please open an issue or contact the repository owner.

---

For further details and tips, visit the [Notion Page](https://yen-lung-huang.notion.site/KEIL-MDK-6a0c48f6123f4da9a6e4cb1625dc8c88?pvs=4).
