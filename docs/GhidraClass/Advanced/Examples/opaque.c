/* ###
 * IP: GHIDRA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
    if (argc != 3){
        printf("\nUsage: %s input1 input2\n\n",argv[0]);
        return EXIT_SUCCESS;
    }
    unsigned long input = strtoul(argv[1], NULL, 10);
    input *= input;
    input = input % 4;
    if (input >= 2){
       asm(".intel_syntax noprefix");
       asm(".byte 0xeb");
       asm(".byte 0x9");
       asm(".att_syntax prefix");
    }
    else {
        unsigned long second = strtoul(argv[2],NULL,10);
        input = second << 2 + input;
        printf("Returning %ld\n", input);
    }
    return input;
}
